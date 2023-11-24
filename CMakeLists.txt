cmake_minimum_required(VERSION 3.0)
project(cts)

# 查找当前目录下的所有.c文件
file(GLOB SOURCES "src/*.c")
include_directories("include")
# 添加可执行文件或库
add_executable(cts ${SOURCES})

target_link_libraries(cts m)
