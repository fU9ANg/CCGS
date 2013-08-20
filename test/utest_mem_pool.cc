
#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "ccgs_common_buffer.h"
#include "ccgs_mem_pool.h"

TEST (MEMPOOL, Malloc)
{
    CommBuf* buf = NULL;
    CMemPool<CommBuf> mempool (1);

#if 1
    ASSERT_EQ (mempool.Size(), 1);
    ASSERT_EQ (mempool.Used(), 0);
    buf = mempool.Malloc ();
    ASSERT_EQ (mempool.Size(), 1);
    ASSERT_EQ (mempool.Used(), 1);
    //ASSERT_EQ ((void*)mempool.Malloc (), NULL);
    //ASSERT_NE ((void*)buf, NULL);
    mempool.Free (buf);
    ASSERT_EQ (mempool.Size(), 1);
    ASSERT_EQ (mempool.Used(), 0);
#endif
}

TEST (MEMPOOL, Free)
{
    CommBuf* buf = NULL;
    CommBuf* buf2= NULL;
    CMemPool<CommBuf> mempool (2);

#if 1
    ASSERT_EQ (mempool.Size(), 2);
    ASSERT_EQ (mempool.Used(), 0);
    buf = mempool.Malloc ();
    ASSERT_EQ (mempool.Size(), 2);
    ASSERT_EQ (mempool.Used(), 1);
    buf2 = mempool.Malloc ();
    ASSERT_EQ (mempool.Size(), 2);
    ASSERT_EQ (mempool.Used(), 2);

    // Free
    mempool.Free (buf);
    ASSERT_EQ (mempool.Size(), 2);
    ASSERT_EQ (mempool.Used(), 1);
    mempool.Free (buf2);
    ASSERT_EQ (mempool.Size(), 2);
    ASSERT_EQ (mempool.Used(), 0);
#endif
}
