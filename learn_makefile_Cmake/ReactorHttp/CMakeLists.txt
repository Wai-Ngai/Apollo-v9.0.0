cmake_minimum_required(VERSION 3.105)
project(HttpWeb)

# 包含头文件路径
include_directories(
    &{PROJECT_SOURCE_DIR}/common 
    &{PROJECT_SOURCE_DIR}/http 
    &{PROJECT_SOURCE_DIR}/reactor 
    &{PROJECT_SOURCE_DIR}/tcp 
    &{PROJECT_SOURCE_DIR}/thread 
)

# 包含各个子目录，每个子目录都有各自的CMakeLists.txt文件
add_subdirectory(common)
add_subdirectory(http)
add_subdirectory(reactor)
add_subdirectory(tcp)
add_subdirectory(thread)

# 链接静态库，库的名字：common、http、reactor、tcp、thread  这里让生成的库名字和文件夹的名字保持一致
link_libraries(common http reactor tcp thread)

# 生成可执行文件，名字：server  依赖于main.cpp
add_executable(server main.cpp)
