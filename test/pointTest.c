//
// Created by Administrator on 3/18/2021.
//
#include <stdio.h>

int main() {
    int var = 10;
    // 定义方式1
    int *key = &var;
    // 定义方式2
    int *key2;
    key2 = &var;
    // 这种指针打印就是打印值而已
    printf("一级指针的内容是%p\n", key);
    printf("一级指针的地址是: %p\n", &key);

    //  二级指针
    int **twice = &key;
    printf("二级指针的值是: %p\n", twice);
    printf("二级指针的地址是: %p\n", &twice);

    // 有别于二级指针    定义完成指针之后, 在指针前端加上*号 表明取这个指针指向的地址中所存的值
    /**
     * 注意!!!! 这种方式是取值   和定义出来的二级指针是不同的
     */
    printf("%d\n", *key2);


}