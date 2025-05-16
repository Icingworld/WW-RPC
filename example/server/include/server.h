#pragma once

#include <test.pb.h>

class TestServiceImpl : public Test::TestService
{
public:
    void login(::google::protobuf::RpcController* controller,
                const ::Test::LoginRequest* request,
                ::Test::LoginResponse* response,
                ::google::protobuf::Closure* done) override
    {
        // 简单验证逻辑
        if (request->username() == "Icingworld" && request->password() == "helloworld") {
            response->set_code(0);
            response->set_msg("Login success");
        } else {
            response->set_code(1);
            response->set_msg("Invalid credentials");
        }

        // 调用回调，通知框架返回响应
        if (done) {
            done->Run();
        }
    }
};
