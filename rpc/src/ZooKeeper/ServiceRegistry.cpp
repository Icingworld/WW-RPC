#include "ServiceRegistry.h"

namespace WW
{

ServiceRegistry::ServiceRegistry(const std::string & ip, const std::string & port, int timeout)
    : _Zk_client()
{
    // 连接 ZooKeeper 服务器
    _Zk_client.start(ip + ":" + port, timeout);
}

ServiceRegistry & ServiceRegistry::getServiceRegistry(const std::string & ip, const std::string & port, int timeout)
{
    static ServiceRegistry registry(ip, port, timeout);
    return registry;
}

bool ServiceRegistry::registerService(const std::string & service_name, const std::string & method_name,
                                      const std::string & ip, const std::string & port)
{
    // 构造路径，规则为："/rpc/" + service_name + "/" + method_name + "/" + ip + ":" + port
    // 如："/rpc/test_service/test_method/101.128.153.35:2499"

    // 由于 ZooKeeper 能够自动递归创建，直接拼接即可

    // 持久节点，用于储存服务和方法
    std::string base_path = "/rpc/" + service_name + "/" + method_name;
    _Zk_client.create(base_path, "", false);

    // 临时节点，当服务下线时会自动从 Zookeeper 注销
    std::string path = base_path + "/" + ip + ":" + port;
    _Zk_client.create(path, "", true);

    return true;
}

} // namespace WW
