cmake_minimum_required(VERSION 3.105)
project(tcp)    

# 链接不到库，直接指定
link_libraries(common http reactor)

aux_source_directory(./ SRC)
add_library(tcp ${SRC})