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
        Node var = (Node) malloc(sizeof(Node));
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
        printf("%d ", node->data);
    }
    printf("\n");
}

/**
 * 相反地，当已具有一个指针，并且希望获取它所引用的对象时，使用间接运算符 *（indirection operator），
 * 有时候这会被称为解引用运算符（dereferencing operator）。
 * 它的操作数必须是指针类型。如果 ptr 是指针，那么 *ptr 就是 ptr 所指向的对象或函数。
 * 如果 ptr 是一个对象指针，那么 *ptr 就是一个左值，可以把它（即 *ptr）当作赋值运算符左边的操作数：
 * @return
 */
void testPoint(ListNode node) {
    while (node.next != NULL) {
        node = *node.next;
        printf("%d ", node.data);
    }
}

/**
 * 运算符 & 和 * 是互补的：如果 x 是一个表达式，用于指定一个对象或一个函数，
 * 那么表达式 *&x 就等于 x。相反地，在形如 &*ptr 的表达式中，
 * 这些运算符会互相抵消，表达式的类型与值等效于 ptr。然而，不管 ptr 是不是左值，&*ptr 都一定不会是左值。
 */

int main() {
    Node node = (Node) malloc(sizeof(Node));
    init(node);
    print(node);

    testPoint(*node);
}