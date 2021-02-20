//
// Created by Administrator on 2/2/2021.
//


#include <stdio.h>
#include <stdbool.h>
#include "tool.h"

#define MAXSIZE 2

/**
 * 定义一个环形的队列 先进先出
 * 定义首尾指针
 * top = end时说明为空
 * top = end + 1时说明队列满了
 * 损失队列最顶端的一个空间
 *
 * 每个top指向的是未存数据的那个空间
 *
 *
 */
typedef struct {
    int top;
    int end;
    int data[MAXSIZE];

} round_stack;

void init(round_stack *var) {
    for (int i = 0; i < MAXSIZE; ++i) {
        var->data[i] = 0;
    }
    var->top = 0;
    var->end = 0;
}

/**
 * push
 * @return
 */
bool push(round_stack *var, int num) {
    if (var->top - var->end == 1) {
        // 此时说明队列已经满了
        return false;
    }
    // 把num存入当前队列顶并且加一操作
    var->data[var->top++] = num;
    return true;
}

/**
 * pop
 * @return
 */
int pop(round_stack *stack) {
    // 这种情况说明栈已经空了, 不能再出栈了
    if (stack->top == stack->end) {
        return 0;
    }
    // 栈顶指针减一
    stack->top--;
    int res = stack->data[stack->top];
    stack->data[stack->top] = 0;
    return res;
}


int main() {
    round_stack stack;
    // 初始化环栈
    init(&stack);
    int a = pop(&stack);
    bool b = push(&stack, 12);
    int c = pop(&stack);
    bool d = push(&stack, 12);
    bool e = push(&stack, 12);
    bool f = push(&stack, 12);
    int g = pop(&stack);
    int h = pop(&stack);
    int i = pop(&stack);

    printf("%d\n%d\n%d\n%d\n%d\n%d", a,b,c,d,e,f);
    printSep();

    printf("%d\n%d\n%d\n", g,h,i);

};

