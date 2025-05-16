#include "zookeeper_client.h"

#include <stdexcept>
#include <sstream>

namespace WW
{

zookeeper_client::zookeeper_client()
    : _Zk_handle(nullptr)
{
}

zookeeper_client::~zookeeper_client()
{
    if (_Zk_handle != nullptr) {
        // 关闭 ZooKeeper 连接
        zookeeper_close(_Zk_handle);
    }
}

void zookeeper_client::connect(const std::string & zk_host, int timeout)
{
    // 初始化 ZooKeeper 连接
    _Zk_handle = zookeeper_init(zk_host.c_str(), watcher, timeout, nullptr, nullptr, 0);

    if (_Zk_handle == nullptr) {
        // 初始化失败
        _Throw_runtime_error("Fail to connect ZooKeeper at: " + zk_host);
    }
}

bool zookeeper_client::create(const std::string & path, const std::string & data, bool ephemeral)
{
    char buffer[512] = {0};
    int flag = 0;
    if (ephemeral) {
        flag = ZOO_EPHEMERAL;
    }

    // 创建一个 znode 节点
    int ret = zoo_create(_Zk_handle, path.c_str(), data.c_str(), data.size(), &ZOO_OPEN_ACL_UNSAFE, flag, buffer, sizeof(buffer));

    if (ret != ZOK) {
        return false;
    }

    return true;
}

bool zookeeper_client::create_recursive(const std::string & path, const std::string & data, bool ephemeral)
{
    std::istringstream iss(path);
    std::string token;
    std::string current;

    int flag = 0;
    if (ephemeral) {
        flag = ZOO_EPHEMERAL;
    }

    while (std::getline(iss, token, '/')) {
        if (token.empty()) {
            continue;
        }

        current += "/" + token;

        if (zoo_exists(_Zk_handle, current.c_str(), 0, nullptr) != ZOK) {
            zoo_create(_Zk_handle, current.c_str(), "", 0, &ZOO_OPEN_ACL_UNSAFE, flag, nullptr, 0);
        }
    }
    return true;
}

std::string zookeeper_client::get_data(const std::string & path)
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

bool zookeeper_client::get_children(const std::string & path, std::vector<std::string> & childs)
{
    // ZooKeeper 内置结构体
    struct String_vector strings;

    int ret = zoo_get_children(_Zk_handle, path.c_str(), 0, &strings);
    if (ret != ZOK) {
        return false;
    }

    for (int i = 0; i < strings.count; ++i) {
        childs.emplace_back(strings.data[i]);
    }

    // 释放分配的内存
    deallocate_String_vector(&strings);

    return true;
}

void zookeeper_client::watcher(zhandle_t * zh, int type, int state, const char * path, void * watcher_ctx)
{
    // TODO
}

void zookeeper_client::_Throw_runtime_error(const std::string & message) const
{
    throw std::runtime_error(message);
}

} // namespace WW
