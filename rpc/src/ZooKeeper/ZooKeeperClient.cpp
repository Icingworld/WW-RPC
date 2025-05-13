#include "ZooKeeperClient.h"

#include <stdexcept>

namespace WW
{

ZooKeeperClient::ZooKeeperClient()
    : _Zk_handle(nullptr)
{
}

ZooKeeperClient::~ZooKeeperClient()
{
    if (_Zk_handle != nullptr) {
        // 关闭 ZooKeeper 连接
        zookeeper_close(_Zk_handle);
    }
}

void ZooKeeperClient::start(const std::string & zk_host, int timeout)
{
    // 初始化 ZooKeeper 连接
    _Zk_handle = zookeeper_init(zk_host.c_str(), watcher, timeout, nullptr, nullptr, 0);

    if (_Zk_handle == nullptr) {
        // 初始化失败
        _Throw_runtime_error("Fail to connect ZooKeeper at: " + zk_host);
    }
}

void ZooKeeperClient::create(const std::string & path, const std::string & data, bool ephemeral)
{
    char buffer[512] = {0};
    int flag = 0;
    if (ephemeral) {
        flag = ZOO_EPHEMERAL;
    }

    // 创建一个 znode 节点
    int ret = zoo_create(_Zk_handle, path.c_str(), data.c_str(), data.size(), &ZOO_OPEN_ACL_UNSAFE, flag, buffer, sizeof(buffer));

    if (ret != ZOK) {
        if (ret == ZNODEEXISTS) {
            // 节点已经存在，创建失败
            // TODO
        } else {
            _Throw_runtime_error("Failed to create znode: " + path + ", code: " + std::to_string(ret));
        }
    }
}

std::string ZooKeeperClient::get_data(const std::string & path)
{
    char buffer[512] = {0};
    int len = sizeof(buffer);

    // 获取节点值
    int ret = zoo_get(_Zk_handle, path.c_str(), 0, buffer, &len, nullptr);

    if (ret != ZOK) {
        return "";
    }
    return std::string(buffer, len);
}

void ZooKeeperClient::watcher(zhandle_t * zh, int type, int state, const char * path, void * watcherCtx)
{
    // TODO
}

void ZooKeeperClient::_Throw_runtime_error(const std::string & message) const
{
    throw std::runtime_error(message);
}

} // namespace WW
