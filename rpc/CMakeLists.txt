file(GLOB_RECURSE RPC_SOURCES "*.cpp" "*.cc")

add_library(ww-rpc STATIC ${RPC_SOURCES})

target_include_directories(ww-rpc PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/config
    ${CMAKE_CURRENT_SOURCE_DIR}/include/log
    ${CMAKE_CURRENT_SOURCE_DIR}/include/zookeeper
    ${CMAKE_CURRENT_SOURCE_DIR}/include/serialization
    ${CMAKE_CURRENT_SOURCE_DIR}/include/client
    ${CMAKE_CURRENT_SOURCE_DIR}/include/server
)

target_link_libraries(ww-rpc PUBLIC
    third-party
)

add_library(WW::RPC ALIAS ww-rpc)
