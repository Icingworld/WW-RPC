#include "ServiceDiscovery.h"

namespace WW
{

ServiceDiscovery::ServiceDiscovery(const std::string & ip, const std::string & port, int timeout)
    : _Zk_client()
{
    // 连接 ZooKeeper 服务器
    _Zk_client.start(ip + ":" + port, timeout);
}

ServiceDiscovery & ServiceDiscovery::getServiceDiscovery(const std::string & ip, const std::string & port, int timeout)
{
    static ServiceDiscovery discover(ip, port, timeout);
    return discover;
}

std::vector<std::string> ServiceDiscovery::discover(const std::string & service_name, const std::string & method_name)
{

}

} // namespace WW
