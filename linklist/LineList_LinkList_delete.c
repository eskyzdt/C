//
// Created by Administrator on 6/2/2021.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int array[MAXSIZE] = {1, 4, 23, 12, 32, 354, 12, 3, 54, 67};

typedef struct ListNode {
    int data;
    struct ListNode *next;
} *Node, ListNode;

void init(Node node) {
    int i = MAXSIZE - 1;
    // 头结点
    node->data = 0;
    node->next = NULL;
    // 头插法
    while (i > -1) {
        Node var = (Node) malloc(sizeof(ListNode));
        var->data = array[i];
        // 原头结点指向的地址赋给新结点
        var->next = node->next;
        // 头结点指向的地址更改为新结点
        node->next = var;
        i--;
    }
}

void print(Node node) {
    while (node->next != NULL) {
        node = node->next;
        printf("%d,", node->data);
    }
}

int main() {
    Node node = (struct ListNode *) malloc(sizeof(ListNode));
    init(node);
    print(node);
}