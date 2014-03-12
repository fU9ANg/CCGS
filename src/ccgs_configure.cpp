
#include "ccgs_configure.h"

Config* Config::config = NULL;

Config* Config::GetInstance ()
{
    if  (NULL == config)
    {
        config = new Config (); 
    }
    return (config);
}

Config::Config ()
{
    //TODO:
}
    
Config::~Config ()
{
    //TODO:
}

void Config::Read (string file)
{
    lua_State* lua = luaL_newstate ();

    // load script file
    int ret = luaL_loadfile (lua, file.c_str ());
    if (ret != 0)
    {
        lua_close (lua);
        return;
    }

    // init lua env
    ret = lua_pcall (lua, 0, 0, 0);
    if (ret != 0)
    {
        lua_close (lua);
        return;
    }

    // DB server address
    lua_getglobal (lua,"db_host");
    db_host = lua_tostring (lua, -1);

    // need username for connect mysql
    lua_getglobal (lua,"db_username");
    db_username = lua_tostring (lua, -1);

    // the data size for transaction, which will
    // determine if a transaction from client would be
    // accepted.
    lua_getglobal (lua, "max_trans_size");
    max_trans_size = lua_tointeger (lua, -1);

    // need passwd for connect mysql
    lua_getglobal (lua,"db_password");
    db_password = lua_tostring (lua, -1);

    // mysql database name
    lua_getglobal (lua,"db_database");
    db_database = lua_tostring (lua, -1);

    // server address
    lua_getglobal (lua,"server_ip");
    server_ip = lua_tostring (lua, -1);

    // listen port
    lua_getglobal (lua,"server_port");
    server_port = lua_tointeger (lua, -1);

    // module_list
    lua_getglobal (lua,"module_list");
    module_list = lua_tostring (lua, -1);

    // memcached server address
    lua_getglobal (lua, "mc_server");
    mc_server = lua_tostring (lua, -1);

    // memcached server port
    lua_getglobal (lua, "mc_port");
    mc_port = lua_tointeger (lua, -1);

    lua_pop (lua, 9);

    lua_close (lua);

    return;
}
