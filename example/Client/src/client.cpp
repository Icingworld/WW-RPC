#include <Client/WWChannel.h>
#include <test.pb.h>

int main()
{
    // 创建 Channel
    WW::WWChannel channel;

    // 创建 stub
    Test::TestService_Stub stub(&channel);

    // 用户名和密码
    std::string username = "Icingworld";
    std::string password = "helloworld";

    // 创建请求消息
    Test::LoginRequest request;
    request.set_username(username);
    request.set_password(password);

    // 创建响应消息
    Test::LoginResponse response;

    stub.login(nullptr, &request, &response, nullptr);

    std::cout << "Response code: " << response.code()
              << ", message: " << response.msg() << std::endl;

    return 0;
}
