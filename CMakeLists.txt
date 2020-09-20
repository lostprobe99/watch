cmake_minimum_required(VERSION 2.8)

project(watch)

# 添加 watch 子目录
aux_source_directory(./src LIB_WATCH)

# 生成链接库
add_library(watch ${LIB_WATCH})

# 指定生成目标
add_executable(test test.cpp)

# 添加链接库
target_link_libraries(test watch)
