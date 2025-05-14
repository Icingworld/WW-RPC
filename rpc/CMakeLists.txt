file(GLOB_RECURSE RPC_SOURCES "*.cpp")

add_library(ww-rpc STATIC ${RPC_SOURCES})

target_include_directories(ww-rpc PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/ZooKeeper"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/Seialization"
)

target_link_libraries(ww-rpc PRIVATE
    third-party
)

add_library(WW::RPC ALIAS ww-rpc)
