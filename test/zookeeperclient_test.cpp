#include <ZooKeeper/ZooKeeperClient.h>

#include <iostream>
#include <cassert>

int main() {
    WW::ZooKeeperClient zkClient;

    try {
        // 启动连接
        zkClient.start("127.0.0.1:2181", 3000);
        std::cout << "[OK] Connected to ZooKeeper." << std::endl;

        // 创建节点
        std::string path = "/test_node";
        std::string data = "hello_zk";

        zkClient.create(path, data);
        std::cout << "[OK] Created node: " << path << std::endl;

        // 获取数据
        std::string fetched = zkClient.get_data(path);
        std::cout << "[OK] Fetched data: " << fetched << std::endl;

        assert(fetched == data);
        std::cout << "[PASS] ZooKeeperClient basic test passed." << std::endl;
    }
    catch (const std::exception & ex) {
        std::cerr << "[FAIL] Exception: " << ex.what() << std::endl;
        return -1;
    }

    return 0;
}
