cmake_minimum_required(VERSION 3.15)
project(person)

# 包含头文件路径
# include_directories(
#     &{PROJECT_SOURCE_DIR}
#     &{PROJECT_SOURCE_DIR}/common
# )

include_directories(${HEAD_PATH})

# 搜索当前目录下的原文件，变成一个库文件
aux_source_directory(./ SRC)

# 如果不通过第二个参数指定生成静态库还是动态库，默认生成的是静态库
add_library(person STATIC ${SRC})