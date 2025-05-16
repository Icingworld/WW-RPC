add_executable(server
    src/server.cpp
    src/test.pb.cc
)

target_include_directories(server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(server PRIVATE
    WW::RPC
)
