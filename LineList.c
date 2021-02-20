//
// Created by Administrator on 2/18/2021.
// seqList线性表的 顺序表示
//
#include <stdio.h>

#define MAXSIZE 50

typedef struct {
    int data[MAXSIZE];
    // 当前长度
    int length;
} SeqList;

void InitStack(SeqList *stack) {
    stack->length = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        stack->data[i] = 0;
    }
    printf("元素初始化完毕");
}

void printAll(SeqList list) {
    for (int i = 0; i < MAXSIZE; ++i) {
        int tem = list.data[i];
        printf("%d ", tem);
    }
}

void insert(SeqList *list, int locate, int a) {
    if (locate < 1 || locate > list->length + 1) {
        return;
    }
    if (list->length >= MAXSIZE) {
        return;
    }
    for (int i = list->length; i >= locate; --i) {
        list->data[i] = list->data[i - 1];
    }
    list->data[locate - 1] = a;
    list->length++;
}

// 获得某一个值的位置
int locateElem(SeqList *list, int a) {
    for (int i = 1; i <= list->length; ++i) {
        if (list->data[i - 1] == a) {
            return i;
        }
    }
    return -1;
}

// 获得某一位置上的元素值
int getElem(SeqList *list, int a) {
    if (a < 1 || a > list->length) {
        return -999;
    }
    return list->data[a - 1];
}

void printElem(SeqList list){
    int leg = list.length;
    for (int i = 1; i <= leg; ++i) {
        printf("%d ", list.data[i-1]);
    }
}

// 删除第i个元素并返回
int deleteElem(SeqList *list, int i){
    if (i < 1 || i > list->length) {
        return -1;
    }
    int returnElem = list->data[i-1];
    // 第一步, 移位操作
    // 从第i个数开始, 它后面的数往前挪一位, 最后把后面没有数字的位置 置为0
    // 这种理解方式, 操作的数为i , i+1... n-1 即可
    // 或者可以理解为从i+1个数开始, 把这个数前移一位, 最后一个数前移后 置0
    // 这种方式, 操作的数为 i+1, i+2... n
    for (int j = i; j < list->length; ++j) {
        // 这里可以打个断点看里面的值
        list->data[j-1] = list->data[j];
    }
    // 第二步, 清0操作  这一步可以不用清,
    list->data[list->length-1] = 0;
    list->length--;
    return returnElem;
}

int length(SeqList list){
    return list.length;
}

int main() {
    SeqList stack;
    InitStack(&stack);
    printf("\n");
    printAll(stack);
    insert(&stack, 1, 1);
    insert(&stack, 1, 2);
    insert(&stack, 1, 3);
    insert(&stack, 1, 4);
    printf("\n");
    printElem(stack);
    printf("\n");
    int x = 2;
    int loc = locateElem(&stack, x);
    printf("%d的位置在第%d位\n",x, loc);
    int elm = getElem(&stack, 4);
    printf("期待输出1: %d\n", elm);
    printf("删除前长度是%d\n", length(stack));
    // 删除位置2上的元素3
    int del = deleteElem(&stack, 2);
    printf("删除后长度是%d\n", length(stack));
    //
    printf("%d已被删除\n", del);
    printElem(stack);
};
