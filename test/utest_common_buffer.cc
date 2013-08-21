
#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "ccgs_common_buffer.h"

TEST (CommBuf, malloc)
{
    struct _buf_test
    {
        int    iflags;
        char   cflags;
    } FTEST;

    (void) memset (&FTEST, 0x00, sizeof (FTEST));
    FTEST.iflags = 1;
    FTEST.cflags = 'a';

    CommBuf* buf = new CommBuf();

    (void) memcpy (buf->Data(), &FTEST, sizeof (FTEST));

    ASSERT_EQ (((struct _buf_test *) buf->Data())->iflags, 1);
    ASSERT_EQ (((struct _buf_test *) buf->Data())->cflags, 'a');

    if (buf)
        delete buf;
}
