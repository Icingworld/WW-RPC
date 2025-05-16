add_subdirectory(muduo)

add_library(third-party INTERFACE)

find_package(Threads REQUIRED)

# Protobuf
find_package(Protobuf REQUIRED)

# ZooKeeper 路径
include_directories(/usr/include)
link_directories(/usr/lib)

target_include_directories(third-party INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/muduo
)

target_link_libraries(third-party INTERFACE
    muduo_base
    muduo_net
    Threads::Threads
    protobuf::libprotobuf
    zookeeper_mt
)