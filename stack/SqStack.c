//
// Created by Administrator on 3/17/2021.
// 顺序栈的实现
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 2

typedef struct {
    int data[MAXSIZE];  // 存放数据的区域
    int top;    // 栈顶指针
} SqStack;

void init(SqStack *stack) {
    stack->top = -1;
}

bool stackEmpty(SqStack stack) {
    if (stack.top == -1) {
        return true;
    }
    return false;
}

/**
 * 这里出栈时用一个入参来保存
 * 出栈操作 [top--]
 *
 * 注意 如果栈空时指针指向0 , 那么出栈操作为[--top]
 * @param stack
 * @return
 */
bool pop(SqStack *stack, int *var) {
    if (stack->top == -1) {
        return false;
    }
    *var = stack->data[stack->top--];
    return true;
}

/**
 * 进栈操作 [++top]
 *  * 注意 如果栈空时指针指向0 , 那么进栈操作为[top++]

 * @param stack
 * @param var
 * @return
 */
bool push(SqStack *stack, int var) {
    if (stack->top == MAXSIZE - 1) {
        return false;
    }
    stack->top++;
    stack->data[stack->top] = var;
    return true;
}

bool getTop(SqStack stack, int *var) {
    if (stack.top == -1) {
        return false;
    }
    *var = stack.data[stack.top];
    return true;
}

/**
 * 注意main函数返回值必须为int
 *
 * @return
 */
int main() {
// 如果top!= -1,则 当前栈顶的元素是 data[top];
// 栈长top + 1
// 栈空判断条件 top == -1
// 栈满判断条件 top == MAXSIZE - 1;
// 栈长 top+1
    SqStack stack;
    init(&stack);
    printf("%d", stack.top);
    push(&stack, 3);
    int *top;
    getTop(stack, top);
    printf("希望top的值是3: %d\n", top);
    push(&stack, 4);
    bool a = push(&stack, 5);
    printf("push 5 的结果是: %d\n", a);

    int *popVar = malloc(sizeof(int));
    pop(&stack, popVar);
    printf("出栈的值为: %d\n", *popVar);

    int popVar2;
    // 这样也可以修改, 把popVar2这个数字的地址传入pop方法, 得到变量的地址，可以通过对地址的操作来访问和改变变量的内容
    pop(&stack, &popVar2);
    printf("出栈的值为: %d\n", popVar2);



    /**
     * 常用语
     * 1. 值传递：函数内改变其值，退出函数后值不变
     * 2. 引用传递：函数内改变其值，退出函数后变量值和函数的更改后值一样
     */

    /**
     * 共享栈的概念:
     * 由于顺序栈的栈底位置相对不变, 我们可以让两个栈共享一个空间
     * 当栈为空时, stack1.top = -1   stack2.top = MAXSIZE
     * 当栈为满时, stack1.top + 1 = stack2.top
     * 进栈: stack1[++top]  stack2[--top]
     * 出栈: stack1[top--]  stack2[top++]
     */
}


