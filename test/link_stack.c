
#include <stdio.h>


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;//结点数据域
    struct StackNode* next;//结点指针域
}StackNode,* Linktop;

//链栈的数据结构
typedef struct LinkStack {
    Linktop top;   //栈顶结点,定义了一个指向上个结构体的指针
    int count;//元素个数
}LinkStack;

//初始化
int InitLinkStack(LinkStack* stack)
{
    if (!stack)     // 等价于 if(stack == NULL)
    {
        return 0;
    }
    stack->top = NULL;
    stack->count = 0;
    return 1;
}
//清空数据，释放结点内存，实际上就是pop所有数据
int ClearLinkStack(LinkStack* stack)
{
    if (!stack||!stack->count)
    {
        return	0;
    }
    while (stack->count)
    {
        StackNode* node = stack->top;
        stack->top = node->next;
        free(node);
        stack->count--;
    }
    return 1;
}
//判断链栈是否为空
int EmptyLinkStack(LinkStack* stack)
{
    if (!stack)
    {
        return 0;
    }
    return stack->count == 0 ? 1 : 0;
}
//获取元素个数
int GetLengthLinkStack(LinkStack* stack)
{
    if (!stack )
    {
        return	-1;
    }
    return stack->count;
}
int GetTop(LinkStack* stack, StackNode** stackNode)
{
    if (!stack)
    {
        return	0;
    }
    *stackNode = stack->top;//将栈顶元素的指针返回，获取指向可修改栈顶元素内容。
    return 1;
}

//弹栈:栈顶指针指向要弹出元素前置结点，然后释放弹出元素内存空间，然后count-1
int pop(LinkStack* stack,int *e)
{
    if (!stack && stack->count)
    {
        return	0;
    }
    StackNode* node = stack->top;
    *e = node->data;
    stack->top = node->next;   //栈顶指针指向新的栈顶元素
    free(node);                //释放元素空间
    stack->count--;
    return 1;
}

//压栈:先将压入元素放入到链表表中，然后再将栈顶指针指向压入的元素，然后count+1.
int push(LinkStack* stack,int e)
{
    if (!stack)
    {
        return 0;
    }
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->next = stack->top;           //将元素加入链表中
    node->data = e;
    stack->top = node;                 //栈顶元素指向压入元素
    stack->count++;
    return 1;
}
int PrintfLinkStack(LinkStack* stack)
{
    if (!stack&&stack->count)
    {
        return 0;
    }
    StackNode* node = stack->top;
    while (node)
    {
        printf("%d,", node->data);
        node = node->next;
    }
    puts("");
    return;
}
int main()
{
    LinkStack stack;
    InitLinkStack(&stack);//初始化
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    puts("链栈元素：");
    PrintfLinkStack(&stack);
    printf("链栈元素个数：%d\n", GetLengthLinkStack(&stack));
    int e1,e2,e3;
    pop(&stack, &e1);
    printf("弹出第一个元素：%d\n", e1);
    pop(&stack, &e2);
    printf("弹出第二个元素：%d\n", e2);
    pop(&stack, &e3);
    printf("弹出第二个元素：%d\n", e3);
    puts("链栈元素：");
    PrintfLinkStack(&stack);
    printf("链栈元素个数：%d", GetLengthLinkStack(&stack));
    printf("\n");
    return 0;
}
