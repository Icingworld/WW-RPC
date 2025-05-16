#pragma once

#include <zookeeper/zookeeper_client.h>

namespace WW
{

/**
 * @brief 服务发现
 */
class service_discovery
{
private:
    zookeeper_client _Zk_client;     // ZooKeeper 客户端

private:
    service_discovery(const std::string & ip, const std::string & port, int timeout = 3000);

    service_discovery() = delete;

    service_discovery(const service_discovery & other) = delete;

    service_discovery & operator=(const service_discovery & other) = delete;

public:
    ~service_discovery() = default;

public:
    /**
     * @brief 获取服务发现单例
     * @param ip ZooKeeper 服务地址
     * @param port ZooKeeper 服务端口
     * @param timeout 超时时间
     * @return 服务发现单例
     */
    static service_discovery & get_service_discovery(const std::string & ip, const std::string & port, int timeout = 3000);

    /**
     * @brief 发现服务
     * @param service_name 服务名
     * @param method_name 方法名
     * @return 储存`ip:port`字符串的数组
     */
    std::vector<std::string> discover_service(const std::string & service_name, const std::string & method_name);
};

} // namespace WW
