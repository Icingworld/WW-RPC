#include <iostream>
#include <cassert>

#include <ZooKeeper/ServiceRegistry.h>
#include <ZooKeeper/ServiceDiscovery.h>

int main()
{
    // 创建一个服务注册实例
    WW::ServiceRegistry & registry = WW::ServiceRegistry::getServiceRegistry("127.0.0.1", "2181");

    // 注册一个服务和方法
    if (!registry.registerService("test_service", "test_method", "127.0.0.1", "6666")) {
        std::cerr << "[FAIL] Register service failed" << std::endl;
        return -1;
    }

    // 创建一个服务发现实例
    WW::ServiceDiscovery & discovery = WW::ServiceDiscovery::getServiceDiscovery("127.0.0.1", "2181");

    // 查询服务和方法
    std::vector<std::string> hosts =  discovery.discoverService("test_service", "test_method");

    if (hosts.size() == 0) {
        std::cerr << "[FAIL] Discover service failed" << std::endl;
        return -1;
    }

    assert(hosts.size() == 1);
    assert(hosts[0] == "127.0.0.1:6666");

    std::cerr << "[PASS] Service test passed" << std::endl;

    return 0;
}