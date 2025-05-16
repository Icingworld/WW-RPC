add_executable(client
    src/client.cpp
    src/test.pb.cc
)

target_include_directories(client PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(client PRIVATE
    WW::RPC
)
