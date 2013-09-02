
#include "ccgs_event_loop.h"

#ifdef __BSD_VISIBLE
#define EVENT_POLL EVBACKEND_POLL
#else
#define EVENT_POLL EVBACKEND_EPOLL
#endif

struct ev_loop* CEvLoop::loop = NULL;
struct ev_io_info CEvLoop::ioarray[MAXFD];
CAtomic<int> CEvLoop::clientcount;

CEvLoop::CEvLoop (string ip, int port)
{
    m_ip = ip;
    m_port = port;
    m_listenfd = socket (AF_INET, SOCK_STREAM, 0);
    SetNonblock  (m_listenfd);
    SetReuseAddr  (m_listenfd);
    SetNodelay  (m_listenfd);

    // init value of all IO to NULL
    for (int i = 0; i< MAXFD; ++i)
    {
        ioarray[i].io = NULL;
    }
}

CEvLoop::~CEvLoop ()
{
    close (m_listenfd);
}

int CEvLoop::StartListen ()
{
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    //servaddr.sin_addr.s_addr = inet_addr (m_ip.c_str ());
    inet_pton  (AF_INET, m_ip.c_str (), &servaddr.sin_addr.s_addr);
    //servaddr.sin_addr.s_addr = htonl  (INADDR_ANY);
    servaddr.sin_port = htons (m_port);

    if (0 != bind (m_listenfd, (struct sockaddr *) &servaddr, sizeof (struct sockaddr)))
    {
        LOG (ERROR) << "bind error %s" << strerror (errno) << endl;
        sleep (1);
        abort (); //致命错误
        return (-1);
    }

    listen (m_listenfd, 10);
    return (m_listenfd);
}

int CEvLoop::DoWork ()
{
    //建立监听
    StartListen ();
    ev_io *ev_io_watcher =  (ev_io*) malloc (sizeof (ev_io));
    //ev_io ev_io_watcher;
    //ev_timer timer;
    CEvLoop::loop = ev_loop_new (EVENT_POLL);

    ev_io_init (ev_io_watcher, AcceptCB, m_listenfd, EV_READ);

    ev_io_start (CEvLoop::loop, ev_io_watcher); 
#if 0
    //定时器
    ev_timer_init (&timer, TimeCB, 5, 5);
    ev_timer_start (CEvLoop::loop,&timer); 
#endif
    LOG (INFO) << "ev_loop started";

    //libev event loop
    ev_loop (CEvLoop::loop, 0);

    ev_loop_destroy (CEvLoop::loop);
    free (ev_io_watcher);
    return 0;
}

/**
 * @brief 接受客户端回调函数
 */
void CEvLoop::AcceptCB (struct ev_loop *loop, ev_io *w, int revents)
{
    struct sockaddr_in clientaddr;
    socklen_t socklen = sizeof (struct sockaddr_in);
    int newfd = accept (w->fd, (struct sockaddr *) &clientaddr, &socklen);

    if (newfd <= 0)
    {
        return;
    }

    printf ("Client connected! fd = [%d] ip = [%s] port=[%d]\n",
            newfd,
            inet_ntoa (clientaddr.sin_addr),
            htons (clientaddr.sin_port) );

    LOG (INFO) << "Client connected! fd = [" << newfd 
        << "] ip = ["<< inet_ntoa (clientaddr.sin_addr)
        << "] port = [" << htons (clientaddr.sin_port) << "]" << endl;

    CEvLoop::SetNonblock (newfd);

    CEvLoop::ioarray[newfd].io = (ev_io*)malloc (sizeof (ev_io));
    CEvLoop::ioarray[newfd].lasttime = ev_time ();

    ev_io_init (CEvLoop::ioarray[newfd].io, RecvCB, newfd, EV_READ);
    ev_io_start (loop, CEvLoop::ioarray[newfd].io);
    CEvLoop::clientcount++;
    return;
}

/**
 * @brief 接受数据回调函数
 */
void CEvLoop::RecvCB (struct ev_loop *loop, ev_io *w, int revents)
{
#define MSG_HEADER_LEN  8

    //从内存池中取出一个buf
    CommBuf* buf = SINGLETON->memPool.Malloc ();

    if (!buf)
    {
        sleep (1);
        printf ("--null buf\n");
        abort ();
        return;
    }

    //收包头长度
    int i = recv_v (w->fd, buf->Data (), MSG_HEADER_LEN);
    if (MSG_HEADER_LEN != (unsigned int)i)
    {
        LOG (ERROR) << w->fd << ":recv head error! actually received len = " << i 
            << " info = " << strerror (errno) << endl;
        SINGLETON->memPool.Free (buf);
        CEvLoop::CloseFD (w->fd);
        return;
    }

    //收包体
    int p = *(int*)buf->Data ();
    cout << "packet_size = " << p << endl;
    buf->Reset ();
    i = recv_v (w->fd, (char*)buf->Data (), p - MSG_HEADER_LEN);

    if ((p - MSG_HEADER_LEN) != i)
    {
        LOG (ERROR) << w->fd << ":recv body error! hope = " << p - MSG_HEADER_LEN << " actually received len = " << i 
            << " info = " << strerror (errno) << endl;
        SINGLETON->memPool.Free (buf);
        CEvLoop::CloseFD (w->fd);
        return;
    }

    buf->usedSize = i;
    cout << "buf->Data() = " << (char*)buf->Data () << endl;
    cout << "buf->usedSize = " << buf->usedSize << endl;
    CEvLoop::ioarray[w->fd].lasttime = ev_time ();
    buf->SetSocket (w->fd);
    //将buf压入队列
    SINGLETON->recvQueue.InQueue (buf);
    return;
}

void CEvLoop::SetNonblock (int fd)
{
    fcntl (fd, F_SETFL, fcntl (fd, F_GETFL, 0) | O_NONBLOCK);
}

void CEvLoop::SetReuseAddr (int fd)
{
    int reuse = 1;
    setsockopt (fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof (reuse));
}

void CEvLoop::SetNodelay (int fd)
{
    int nodelay = 1;
    setsockopt (fd, IPPROTO_TCP, TCP_NODELAY, &nodelay, sizeof (nodelay));
}

void CEvLoop::CloseFD (int fd)
{
    struct sockaddr_in remote_addr;
    socklen_t socklen = sizeof (struct sockaddr_in);
    getpeername (fd, (struct sockaddr*)&remote_addr, &socklen);

    printf ("Client disconnected! fd = [%d] ip = [%s] port=[%d]\n",
            fd,
            inet_ntoa (remote_addr.sin_addr),
            htons (remote_addr.sin_port) );

    LOG (INFO) << "Client disconnected! fd = [" << fd 
        << "] ip = ["<< inet_ntoa (remote_addr.sin_addr)
        << "] port = [" << htons (remote_addr.sin_port) << "]" <<endl;

    close (fd);
    ev_io_stop (loop, CEvLoop::ioarray[fd].io);
    free (CEvLoop::ioarray[fd].io);
    CEvLoop::ioarray[fd].io = NULL;
    CEvLoop::clientcount--;
    //ROOMMANAGER->del_client (fd);
}

void CEvLoop::TimeOutCB (struct ev_loop* loop, struct ev_timer *timer, int revents)
{
    ev_tstamp now = ev_time ();

    for (register int i = 0; i < MAXFD; ++i)
    {
        if  (NULL != ioarray[i].io)
        {
            //检测超时断开
            if (TIMEOUT < now - ioarray[i].lasttime)
            {
                LOG (INFO) << i << " now: "<< now << " last recv data:" << ioarray[i].lasttime ;
                //CEvLoop::closefd (i);
            }
        }
    }
    return;
}

int CEvLoop::GetClientCount ()
{
    return CEvLoop::clientcount.Value ();
}
