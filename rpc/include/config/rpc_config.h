#pragma once

#include <string>

namespace WW
{

/**
 * @brief RPC 配置
*/
class rpc_config
{
private:
    rpc_config();

    rpc_config(const rpc_config & other) = delete;

    rpc_config & operator=(const rpc_config & other) = delete;

public:
    ~rpc_config();

public:
    static rpc_config & get_rpc_config();

    std::string get_zookeeper_host();

    std::string get_zookeeper_ip();

    std::string get_zookeeper_port();

    int get_zookeeper_timeout();

    std::string get_local_host();

    std::string get_local_ip();

    std::string get_local_port();
};

} // namespace WW
