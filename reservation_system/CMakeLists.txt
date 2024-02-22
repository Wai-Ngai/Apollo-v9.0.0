cmake_minimum_required(VERSION 3.15)
project(RESERVATION-SYSTEM)


# 头文件目录
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/common)

# 包含头文件路径
# include_directories(${HEAD_PATH})

# 包含头文件路径
include_directories(
    &{PROJECT_SOURCE_DIR}/common  
    &{PROJECT_SOURCE_DIR}/person 
)


# 包含各个子目录
add_subdirectory(common)
add_subdirectory(person)


# 链接静态库，库的名字：person，这里让生成的库名字和文件夹的名字保持一致
link_libraries(person common)

# 生成可执行文件，名字：test  依赖于main.cpp
add_executable(test ReservationSystem.cpp)
