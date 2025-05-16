#pragma once

#include <zookeeper/zookeeper_client.h>

namespace WW
{

/**
 * @brief 服务注册
 */
class service_registry
{
private:
    zookeeper_client _Zk_client;     // ZooKeeper 客户端

private:
    service_registry(const std::string & ip, const std::string & port, int timeout = 3000);

    service_registry() = delete;

    service_registry(const service_registry & other) = delete;

    service_registry & operator=(const service_registry & other) = delete;

public:
    ~service_registry() = default;

public:
    /**
     * @brief 获取服务注册单例
     * @param ip ZooKeeper 服务地址
     * @param port ZooKeeper 服务端口
     * @param timeout 超时时间
     * @return 服务注册单例
     */
    static service_registry & get_service_registry(const std::string & ip, const std::string & port, int timeout = 3000);

    /**
     * @brief 注册服务
     * @param service_name 服务名
     * @param method_name 方法名
     * @param ip 服务所在地址
     * @param port 服务所在端口
     */
    bool register_service(const std::string & service_name, const std::string & method_name,
                          const std::string & ip, const std::string & port);
};

} // namespace WW
