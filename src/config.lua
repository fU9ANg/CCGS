
--[[
--  config file of ecServer
--]]

-- Database host and port
db_host="tcp://127.0.0.1:3306";

-- Username for connection to DB
db_username="root";

-- Password for connection to DB
db_password="123123";

-- Which name of Database
db_database="teaching_db";

-- ecServer Port
server_port=8888;

-- module list
module_list="devel/mymodule.so:0"

-- ecServer IP
--server_ip="0.0.0.0";
server_ip="192.168.0.254";
--server_ip="172.16.10.103";
-- memcached server
mc_server="172.16.10.103"

-- memcached server port
mc_port=11211
