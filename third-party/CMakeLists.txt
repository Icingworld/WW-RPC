add_library(third-party INTERFACE)

find_package(Threads REQUIRED)

# ZooKeeper 路径
include_directories(/usr/include)
link_directories(/usr/lib)

target_link_libraries(third-party INTERFACE
    Threads::Threads
    zookeeper_mt
)