#include "service_discovery.h"

namespace WW
{

service_discovery::service_discovery(const std::string & ip, const std::string & port, int timeout)
    : _Zk_client()
{
    // 连接 ZooKeeper 服务器
    _Zk_client.connect(ip + ":" + port, timeout);
}

service_discovery & service_discovery::get_service_discovery(const std::string & ip, const std::string & port, int timeout)
{
    static service_discovery discovery(ip, port, timeout);
    return discovery;
}

std::vector<std::string> service_discovery::discover_service(const std::string & service_name, const std::string & method_name)
{
    // 构造路径
    std::string base_path = "/" +service_name + "/" + method_name;

    std::vector<std::string> childs;

    _Zk_client.get_children(base_path, childs);

    return childs;
}

} // namespace WW
