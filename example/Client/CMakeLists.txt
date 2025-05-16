add_executable(client
    src/client.cpp
    ../proto/test.pb.cc
)

target_include_directories(client PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../proto
)

target_link_libraries(client PRIVATE
    WW::RPC
)
