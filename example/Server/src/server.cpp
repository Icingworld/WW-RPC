#include "server.h"

#include <Server/Dispatcher.h>

int main()
{
    // 实例化服务
    TestServiceImpl loginService;

    // 向分配器注册服务
    WW::Dispatcher dispatcher;
    dispatcher.registerService(&loginService);

    // 启动分配器
    dispatcher.run();

    return 0;
}
