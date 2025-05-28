# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(1003_Emergency_Main 1003_Emergency_Main.c
        1003_Emergency.c
        1003_Emergency.h)
