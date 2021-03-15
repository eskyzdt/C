#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100
typedef struct {
    int data[MAXSIZE];
    int top;
} stack_timber;

typedef struct {


} ;


void initStack(stack_timber *q) {
    q->top = -1;
    for (int i = 0; i < MAXSIZE; ++i) {
        q->data[i] = 0;
        printf("第%d个元素初始化\n", i);
    }
}

int pop(stack_timber s) {
    s.top--;
    int result = s.data[s.top];
    s.data[s.top] = 0;
    return result;
}

bool push(stack_timber *s, int num) {
    if (s->top == MAXSIZE) {
        return false;
    }
    s->data[s->top++] = num;
    return true;
}

int get(stack_timber *s) {

    if (s->top < 1) {
        return 0;
    }
    return s->data[s->top - 1];
}


int main() {
    stack_timber a;
    initStack(&a);
    push(&a, 111);
    int b =  get(&a);
    printf("%d", b);


}