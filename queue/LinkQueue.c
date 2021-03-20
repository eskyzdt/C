//
// Created by Administrator on 3/20/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAXSIZE 10

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} *LinkQueue;

void init2(LinkQueue queue) {
    // 用这个会报错, 不能把堆内存的地址分配到一个栈内存上
    queue->rear = (LinkNode *) malloc(sizeof(LinkNode));
    queue->front = queue->rear;
    // 初始化的时候不要忘了把头结点的下一个指针置为NULL
    queue->front->next = NULL;
}

// 这里不用返回值来获取的话, 子函数修改后的内容到了main函数中直接就失效了,
// 因为:在main函数中声明的是静态内存分配, 静态内存分配是分配在栈中的,而malloc是在堆内存中动态内存分配,
LinkQueue init() {
    LinkQueue queue = malloc(sizeof(LinkQueue));
    queue->rear = (LinkNode *) malloc(sizeof(LinkNode));
    queue->front = queue->rear;
    // 初始化的时候不要忘了把头结点的下一个指针置为NULL
    queue->front->next = NULL;
    return queue;
}

bool en_queue(LinkQueue queue, int var) {
    LinkNode *tem = (LinkNode *) malloc(sizeof(LinkNode));
    // 初始化这个结点
    tem->data = var;
    tem->next = NULL;
    // 把原尾结点的 下一个结点置为新的结点
    queue->rear->next = tem;
    // 把队尾指针置为最后一个
    queue->rear = tem;
}

bool de_queue(LinkQueue queue, int *var) {
    // 空队列
    if (queue->front == queue->rear) {
        return false;
    }
    //
    // 找一个变量暂存这个要被释放的
    // 由于有一个头结点,所以头结点的下一个才是真正的第一个结点
    LinkNode *tem = queue->front->next;
    // 存值
    *var = tem->data;
    // 这里注意一下, 不是操作头结点本身, 而是操作头结点所指向的next这个地址
    queue->front->next = tem->next;
    free(tem);
    return true;
}

// 判断是否为空队列
bool is_empty(LinkQueue queue) {
    // 如果只有一个元素说明queue->front->next == queue->rear
    // 而空是queue->front == queue->rear;
    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}

int main() {
    // 用这个会报错
    /*  LinkQueue queue2;
      init2(queue2);*/

    LinkQueue queue = init();
    en_queue(queue, 3);
    en_queue(queue, 5);
    int *var;
    de_queue(queue, var);
    printf("出队列的数为%d\n", *var);
    printf("是否为空: %d", is_empty(queue));
};