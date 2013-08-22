﻿
#ifndef _CCGS_CONFIGURE_H_
#define _CCGS_CONFIGURE_H_

#include <stdio.h>
#include <string>

#include "lua5.2/lua.hpp"

using namespace std;

class Config
{
    public:
        ~Config ();
        static class Config* GetInstance ();
        void Read (string file);

    public:
        string  db_host;
        string  db_username;
        string  db_password;
        string  db_database;
        string  server_ip;
        string  module_list;

        // memcached config item of server 
        string  mc_server;
        int     mc_port;

        int     server_port;

    private:
        Config();
        static class Config* config;
};

#define CONFIG Config::GetInstance()

#endif
