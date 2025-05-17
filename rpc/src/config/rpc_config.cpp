#include "rpc_config.h"

namespace WW
{

rpc_config::rpc_config()
{

}

rpc_config::~rpc_config()
{

}

rpc_config & rpc_config::get_rpc_config()
{
    static rpc_config config;
    return config;
}

std::string rpc_config::get_zookeeper_host()
{
    return "127.0.0.1:2181";
}

std::string rpc_config::get_zookeeper_ip()
{
    return "127.0.0.1";
}

std::string rpc_config::get_zookeeper_port()
{
    return "2181";
}

std::string rpc_config::get_local_host()
{
    return "127.0.0.1:6666";
}

std::string rpc_config::get_local_ip()
{
    return "127.0.0.1";
}

std::string rpc_config::get_local_port()
{
    return "6666";
}



} // namespace WW
