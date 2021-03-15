#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 5

// 这里的top指针指向的是最上方的已赋值元素

typedef struct {
    int data[MAXSIZE];
    int top;
} stack_timber;

/**
 * 初始化时指针为-1
 * @param q
 */
void initStacks(stack_timber *q) {
    q->top = -1;
    for (int i = 0; i < MAXSIZE; ++i) {
        q->data[i] = 0;
        printf("第%d个元素初始化\n", i);
    }
}

/**
 * 出栈时栈顶指针减一
 *
 * @param s
 * @return
 */
int pop(stack_timber *s) {
    if (s->top == -1) {
        return 0;
    }
    int result = s->data[s->top];
    s->data[s->top] = 0;
    s->top--;
    return result;
}

bool push(stack_timber *s, int num) {
    if (s->top == MAXSIZE - 1) {
        return false;
    }
    s->top++;
    s->data[s->top] = num;
    return true;
}

int get(stack_timber *s) {
    if (s->top < 0) {
        return 0;
    }
    return s->data[s->top];
}


int main() {
    stack_timber a;
    initStacks(&a);
    push(&a, 111);
    push(&a, 112);
    push(&a, 113);
    push(&a, 114);
    push(&a, 115);
    bool res1 = push(&a, 116);
    printf(res1 == true ? "1\n": "2\n");
    int b =  get(&a);
    printf("%d", b);

}