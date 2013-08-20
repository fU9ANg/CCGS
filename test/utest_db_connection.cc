
#include <limits.h>
#include "gtest/gtest.h"
#include "ccgs_configure.h"
#include "ccgs_db_connection.h"

#define CONFIGFILE   "../src/config.lua"

TEST (DBCONNECTION, Init)
{
    CONFIG->Read (CONFIGFILE);

    ASSERT_EQ (DATABASE->Init (CONFIG->db_host,
                               CONFIG->db_username,
                               CONFIG->db_password,
                               CONFIG->db_database), true);
}
