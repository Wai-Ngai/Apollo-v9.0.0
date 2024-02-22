cmake_minimum_required(VERSION 3.105)

# 和目录的名字保持一致，一看就知道这个脚本文件属于哪个目录
project(common)    

# 搜索当前目录下的原文件，变成一个库文件，指定搜索的路径./，定一个变量SRC用来保存搜索的结果 
aux_source_directory(./ SRC)

# 如果不通过第二个参数指定生成静态库还是动态库，默认生成的是静态库
add_library(common STATIC ${SRC})