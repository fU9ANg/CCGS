
#include "ccgs_manager.h"

CManager::CManager ()
{
    threadPool = new CThreadPool (5);
    fileLock   = 0;
}

CManager::~CManager ()
{
    // TODO:
}

bool CManager::InitSystemManager ()
{
    //initialize module manager.
    if (!SINGLETON->moduleManager.init ()) {
        printf ("[ERROR] -- Module: Initialized modules failed.\n");
        return false;
    }

    //load all modules configuraed in file.
    if (!SINGLETON->moduleManager.load (CONFIG->module_list)) {
        SINGLETON->moduleManager.uninit ();
        printf ("[ERROR] -- Module: load modules failed.\n");
        return false;
    }

    return true;
}

void CManager::ReleaseSystem ()
{
    //unload all modules.
    SINGLETON->moduleManager.unload ();

    //clean all resources used to manage modules.
    SINGLETON->moduleManager.uninit ();
}

int CManager::Process (int argc, char** argv)
{
    signal (SIGINT,  SIG_IGN);
    signal (SIGPIPE, SIG_IGN);
    signal (SIGQUIT, SIG_IGN);
    signal (SIGTERM, SigHandler);

    int opt = getopt (argc, argv, "udsv");
    if ( -1 == opt)
    {
        printf ("argv error\n");
        return (-1);
    }

    int pid = 0;
    switch (opt)
    {
        case 's':
            pid = fork ();
            if (0 < pid)
                return (0);
            break;

        case 'd':
            if (true != Lock (LOCK_NOWAIT))
            {
                printf("Server already running!\n");
                return 0;
            } 
            // Init logging API of google
            assert (0 == system ("mkdir -p logs"));
            google::InitGoogleLogging (argv[0]);
            google::SetLogDestination (google::INFO, "./logs/info");
            google::SetLogDestination (google::WARNING, "./logs/warning");
            google::SetLogDestination (google::ERROR, "./logs/error");
            google::SetStderrLogging  (google::ERROR + 1);
            CONFIG->Read (CONFIGFILE);
#if 0
            //connect to database.
            if (!DATABASE->Init(CONFIG->db_host, \
                                CONFIG->db_username, \
                                CONFIG->db_password, \
                                CONFIG->db_database))
            {
                printf("[ERROR] -- Database: Please check database configure file\n");
                return 0;
            }
#endif
            if (!this->InitSystemManager ()) {
                return -1;
            }
            // RUN
            this->Run ();

            this->ReleaseSystem ();
            break;
    case 'u':
        if (true == Lock (LOCK_NOWAIT))
        {   
            Lock (UNLOCK);
            printf ("No process!\n");
        }
        else
        {
            printf ("Find process! stopping...\n");
            assert (0 == system ("cat .lock|xargs kill -15"));
        }

        printf ("stop\n");
        break;
        
    case 'v':
        printf ("compiled at %s,%s\n",__DATE__,__TIME__);
        break;
        
    default:
        break;
    }

    return (0);
}

void CManager::SigHandler (int signo)
{
    printf ("get exit signal\n");
    LOG (INFO) << "server stoped";
    raise (SIGKILL);
    raise (SIGRTMIN);
    //threadPool->kill ();
    return;
}

/**
 *主循环
 */
int CManager::Run ()
{
    printf ("server running...\n");

    threadPool->Start ();
    CEvLoop* evloop = new CEvLoop (CONFIG->server_ip.c_str(), CONFIG->server_port);
    printf ("server ip = [%s], port = [%d]\n", CONFIG->server_ip.c_str (), CONFIG->server_port);
    RecvTask* precv = new RecvTask ();
    SendTask* psend = new SendTask ();

    threadPool->PushTask (evloop);
    threadPool->PushTask (precv);
    threadPool->PushTask (psend);

    LOG(INFO) << "server start success!";

    // Loop and process
    while (true)
    {
        LOG (INFO) << "new client count = " << evloop->GetClientCount () << endl;
        sleep (5);
    }

    threadPool->Kill ();
    return (0);
}

bool CManager::Lock (int mode)
{
    char szPid[32] = {0};
    snprintf (szPid, 32, "%ld", (long) getpid ());

    if (0 == fileLock) {
        fileLock = open ("./.lock", O_RDWR|O_CREAT, 0640);
    }

    if (fileLock < 0) {
        return false;
    }

    if (0 != flock (fileLock, mode)) {
        return false;
    }

    if (UNLOCK == mode) {
        close (fileLock);
    }
    else {
        if ( 0 == ftruncate (fileLock, 0)) {
            if (0 >= write (fileLock, szPid, strlen (szPid))) {
                printf("write pid file error!\n");
            }
        }
        else {
            printf("write pid file error!\n");
            sleep(1);
            abort();
        }
    }
    return (true);
}
