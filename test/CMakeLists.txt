# zookeeperclient_test
add_executable(zookeeperclient_test
    src/zookeeperclient_test.cpp
)

target_link_libraries(zookeeperclient_test PRIVATE
    WW::RPC
)

# serialization_test
add_executable(serialization_test
    src/serialization_test.pb.cc
    src/serialization_test.cpp
)

target_include_directories(serialization_test PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(serialization_test PRIVATE
    WW::RPC
)
