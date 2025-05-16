file(GLOB_RECURSE RPC_SOURCES "*.cpp" "*.cc")

add_library(ww-rpc STATIC ${RPC_SOURCES})

target_include_directories(ww-rpc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ZooKeeper
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Serialization
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Client
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Server
)

target_link_libraries(ww-rpc PUBLIC
    third-party
)

add_library(WW::RPC ALIAS ww-rpc)
