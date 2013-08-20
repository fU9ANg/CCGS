
#include <limits.h>
#include "gtest/gtest.h"
#include "ccgs_configure.h"

#define CONFIGFILE   "../src/config.lua"

TEST (Configure, Read)
{
    CONFIG->Read (CONFIGFILE);

    ASSERT_EQ (CONFIG->db_username, "root");
    ASSERT_EQ (CONFIG->db_password, "123123");
    ASSERT_EQ (CONFIG->db_database, "teaching_db");

    ASSERT_EQ (CONFIG->server_ip, "192.168.0.254");
    ASSERT_EQ (CONFIG->module_list, "xxxx");
    ASSERT_EQ (CONFIG->mc_server, "172.16.10.103");
    ASSERT_EQ (CONFIG->mc_port, 11211);

    ASSERT_EQ (CONFIG->server_port, 9999);
    ASSERT_EQ (CONFIG->db_host, "tcp://127.0.0.1:3306");
}
