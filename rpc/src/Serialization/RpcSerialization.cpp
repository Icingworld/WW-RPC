#include "RpcSerialization.h"

#include <Serialization/RpcHeader.pb.h>

namespace WW
{

bool RpcSerialization::serialize(const std::string & service_name,
                                 const std::string & method_name,
                                 const google::protobuf::Message & args,
                                 std::string & out_buffer)
{

}

bool RpcSerialization::deserialize(const std::string & in_buffer,
                                   std::string & service_name,
                                   std::string & method_name,
                                   std::string & args_data)
{
    
}

} // namespace WW
