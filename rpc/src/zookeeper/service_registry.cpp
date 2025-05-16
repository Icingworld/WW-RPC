#include "service_registry.h"

namespace WW
{

service_registry::service_registry(const std::string & ip, const std::string & port, int timeout)
    : _Zk_client()
{
    // 连接 ZooKeeper 服务器
    _Zk_client.connect(ip + ":" + port, timeout);
}

service_registry & service_registry::get_service_registry(const std::string & ip, const std::string & port, int timeout)
{
    static service_registry registry(ip, port, timeout);
    return registry;
}

bool service_registry::register_service(const std::string & service_name, const std::string & method_name,
                                      const std::string & ip, const std::string & port)
{
    // 构造路径，规则为："/" + service_name + "/" + method_name + "/" + ip + ":" + port
    // 如："/test_service/test_method/101.128.153.35:2499"

    // 持久节点，用于储存服务和方法
    std::string base_path = "/" + service_name + "/" + method_name;
    if (!_Zk_client.create_recursive(base_path, "", false)) {
        return false;
    }

    // 临时节点，当服务下线时会自动从 Zookeeper 注销
    std::string path = base_path + "/" + ip + ":" + port;
    if (!_Zk_client.create(path, "", true)) {
        return false;
    }

    return true;
}

} // namespace WW
