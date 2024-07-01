project(SRC)

# 包含头文件路径
include_directories(${HEAD_PATH})
# 库文件搜索路径
link_directories(${THIRD_PARTY})

# 生成可执行文件，名字：test  依赖于main.cpp
add_executable(add_test add_test.cpp add_int.cpp)
# 链接外部库
target_link_libraries(add_test libgtest.a libgtest_main.a)
# target_link_libraries(add_test libgmock.a libgmock_main.a)


add_executable(student_test student_test.cpp)
target_link_libraries(student_test libgtest.a libgtest_main.a)