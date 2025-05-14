# zookeeperclient_test.cpp
add_executable(zookeeperclient_test
    zookeeperclient_test.cpp
)

target_link_libraries(zookeeperclient_test PRIVATE
    WW::RPC
)