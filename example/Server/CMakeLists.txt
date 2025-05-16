add_executable(server
    src/server.cpp
    ../proto/test.pb.cc
)

target_include_directories(server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../proto
)

target_link_libraries(server PRIVATE
    WW::RPC
)
