//
// Created by Administrator on 3/18/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 链栈的优点是便于多个栈共享存储空间
 * 且不存在栈满上溢的情况
 */
/**
 * 这种结构和单链表的结构一致
 * 但是规定所有的操作都在表头进行
 */
// 这里是没有头结点的链栈
typedef struct LinkStack {
    int data;
    struct LinkStack *next;
} *LinkStack;

// 这种方式增加了一个LNode, 方便定义带头结点的结构
typedef struct LinkStackHead {
    int data;
    struct LinkStackHead *next;
} LNode, *LinkStackHead;
