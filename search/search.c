//
// Created by Administrator on 5/25/2021.
//

#include <stdio.h>

#define MAXSIZE 11
// 11个数, 0号位储存的值作为哨兵
int array[MAXSIZE] = {0, 33, 23, 123, 554, 678, 9, 34, 237, 56678, 345};

/**
 *
 * @param list
 * @param var 待查找的数据
 * @return
 */
int main() {
    // 待搜索的数
    int var = 9;
    // 放到数组的0号位
    array[0] = var;
    int flag = var;
    int i;
    for (i = MAXSIZE - 1; flag != array[i]; --i) {

    };
    printf("数字%d在第%d个", var, i);
}