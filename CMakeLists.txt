cmake_minimum_required(VERSION 3.17)
project(c_construct C)

set(CMAKE_C_STANDARD 99)
# 在这里把.c文件写为需要运行的文件,则cmake会帮用户自动编译
#  是程序运行时文件名
add_executable(study linklist/LineList_LinkList_delete.c)