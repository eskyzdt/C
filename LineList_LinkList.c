//
// Created by Administrator on 2/20/2021.
//
// 链表有头指针指向头结点, 如果头指针为null则说明是个空链表
// 为了操作方便,经常会设置一个头结点
// 如果不设置头结点, 对第一个结点的处理需要去判空
// 如果设置了头结点,对于所有结点的操作都是一致的,头指针永远指向头结点, 只是空表时头结点的指针域为空而已
#include <stdio.h>
#include <stdlib.h>

typedef struct lineList{
    int a;
    struct LineList *list;
}LineList;

void InitList(LineList *list) {
    int *a = (int*)malloc(1);

}


int main() {
}
