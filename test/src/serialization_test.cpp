#include <iostream>
#include <cassert>

#include <Serialization/RpcSerialization.h>
#include <serialization_test.pb.h>  

int main()
{
    // 创建一条测试消息
    TestMessage msg;
    msg.set_id(42);
    msg.set_msg("Hello, RPC!");
    
    // 测试序列化
    std::string serialized_str;

    if (!WW::RpcSerialization::serialize("test_service", "test_method", msg, serialized_str)) {
        std::cerr << "Serialization failed!" << std::endl;
        return -1;
    }

    std::cout << "[ok]Serialization success." << std::endl;

    // 测试反序列化
    std::string service_name;
    std::string method_name;
    TestMessage get_msg;

    if (!WW::RpcSerialization::deserialize(serialized_str, service_name, method_name, get_msg)) {
        std::cerr << "Deserialization failed!" << std::endl;
        return -1;
    }

    assert(service_name == "test_service");
    assert(method_name == "test_method");
    assert(get_msg.id() == 42);
    assert(get_msg.msg() == "Hello, RPC!");

    std::cout << "[ok]Deserialization success." << std::endl;
    std::cout << "[PASS]Serialization Test Passed." << std::endl;

    return 0;
}
