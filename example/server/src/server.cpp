#include "server.h"

#include <server/rpc_dispatcher.h>

int main()
{
    // 实例化服务
    TestServiceImpl login_service;

    // 向分配器注册服务
    WW::rpc_dispatcher dispatcher;
    dispatcher.register_service(&login_service);

    // 启动分配器
    dispatcher.run();

    return 0;
}
