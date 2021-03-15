//
// Created by Administrator on 2/20/2021.
//
// 链表有头指针指向头结点, 如果头指针为null则说明是个空链表
// 为了操作方便,经常会设置一个头结点
// 如果不设置头结点, 对第一个结点的处理需要去判空
// 如果设置了头结点,对于所有结点的操作都是一致的,头指针永远指向头结点, 只是空表时头结点的指针域为空而已
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

// 这里array数组是9个数,而maxsize为10, 我在做循环的时候, 少的那一个会自动置为0
int array[MAXSIZE] = {23, 123, 554, 678, 9, 34, 237, 56678, 345};

typedef struct linkList {
    int var;
    struct linkList *next;
} linkList;

// 头插法初始化链表
linkList InitListFront(struct linkList *list) {
    // printf("%d\n", sizeof(struct linkList));  16
    //  printf("%d\n", sizeof(int));  4
    // 这里分配头结点
    // 前缀可以去掉,写成 list =  malloc(sizeof(struct linkList));
    // 这里不分配也行, 系统会在栈中自动分配一个地址, 如果用malloc, 会在堆中初始化
    list = (linkList *) malloc(sizeof(struct linkList));
    // 设置头结点的指针为null, 它将是以后的最后一个结点
    list->next = NULL;
    // 两种插入方式
    int type = 1;
    if (type == 1) {
        // type == 1, 这种方式是把头结点每次向后移,
        for (int i = 0; i < MAXSIZE; ++i) {
            // 1.创建一个新结点
            // 先分配地址
            linkList *node = (struct linkList *) malloc(sizeof(struct linkList));
            // 由于是采用头插法, 以后它是第一个, 所以它指向之前的头结点地址
            node->next = list;
            // 把原头结点list的值设置为当前数
            list->var = array[i];
            // 2.这个新结点变为了新的头指针
            list = node;
        }
    }
    // type == 2 , 这种方式是书上的模式,头结点不动, 只动后面的
    if (type == 2) {
        for (int i = 0; i < MAXSIZE; ++i) {
            linkList *node = (linkList *) malloc(sizeof(linkList));
            node->var = array[i];
            // 头插
            // 错误代码node->next = list;
            // 错误代码list = node;
            // 正确代码
            node->next = list->next;
            list->next = node;
        }
    }
    //scanf("%d", &x);
    // 结束
    return *list;
}

// 尾插法 初始化链表并设置第一个数
linkList InitListEnd(linkList *list) {
    // 头结点设置为null
    list->next = NULL;
    // 设置一个尾结点;
    linkList *endNode;
    // 尾结点赋值给当前最后一个结点, 目前是头结点, 这时操作endNode即是操作list
    endNode = list;
    for (int i = 0; i < MAXSIZE; ++i) {
        linkList *node = (linkList *) malloc(sizeof(linkList));
        node->var = array[i];
        // 尾结点的指针指向这个新建的结点
        endNode->next = node;
        // 尾结点定义为新建的这个结点
        endNode = node;
    }
    // 最后把尾结点的指针设置为null
    endNode->next = NULL;
    return *list;
}

// 按值查找, 返回-999说明未查到
linkList *locateElem(linkList list, int var) {
    /*// 打个tag
    int i = 0;
    linkList *node = list;
    int flag = -999;
    while (node->next != NULL) {
        i++;
        node = node->next;
        if (var == node->var) {
            flag = i;
            break;
        }
    }*/
    linkList *node = list.next;
    while (node != NULL && node->var != var) {
        node = node->next;
        // return node;
    }
    return node;

}

// 按位查找
linkList *getElem(linkList list, int index) {
    // 如果是0位置, 返回头结点
    if (index == 0) {
        return &list;
    }
    if (index < 0) {
        return NULL;
    }
    int count = 1;
    linkList *node = list.next;
//    while (node != NULL && index != count) {
// 上面可以简写为下面这种书上的
    while (node && count < index) {
        count++;
        node = node->next;
    }
    // index大于表长则返回null
    return node;
}

// 往list表中的index位置插入一个元素var
linkList *insertElem(linkList *list, int index, int var) {
    // 保存头结点
    linkList *node = list;
    // 找到对应的结点
    list = getElem(*list, index);
    linkList *p = malloc(sizeof(linkList));
    p->var = var;
    p->next = list->next;
    list->next = p;
    list = node;
    return list;
}

// 删除第index个元素 这里时间复杂度是O(n) 但如果已经给了结点地址,可以简化复杂度到O(1)
linkList *deleteElem(linkList *list, int index) {
    // 查找元素的时间复杂度是O(n)
    linkList *node = getElem(*list, index - 1);
    linkList *p = node->next;
    node->next = p->next;
    free(p);
}

//
linkList *deleteElemAddress(linkList *list, linkList *node) {
    linkList *next = node->next;
    // 把要删除的结点的值和它的下一个结点的值互换
    node->var = next->var;
    // 把当前结点直接指向下下结点
    node->next = next->next;
    free(next);
}


void printAll(struct linkList *list) {
// 对于这种带头结点的指针, 第一个结点的处理逻辑和后面的处理逻辑都是一样的
    // 头结点的指针赋值给lnode
    struct linkList *headPoint = list;
    // 如果头结点的指针不为null, 则找第一个结点的指针
    printf("该链表所有的值是:");
    while (headPoint->next != NULL) {
        // 指针移到下一个
        headPoint = headPoint->next;
        printf("%d ", headPoint->var);
    }
    printf("\n");

// 如果是不带头结点的链表, 那么对于首元素的判断要单独判断
    /*
    if (list = NULL) {
        return;
    } else {
        printf("第一个%d\n", list->var);
    }
    while (list->next != NULL) {
        list = list->next;
        printf("%d", list->var);
    }

*/}


int length(linkList list) {
    int count = 0;
    linkList *node = list.next;
    while (node != NULL) {
        node = node->next;
        count++;
    }
    return count;
}

int main() {

    // 头插法 初始化链表, 返回值是一个初始化完毕的链表, 值是反序的,第一个是0
    linkList list;
    list = InitListFront(&list);
    printAll(&list);

    // 尾插法 初始化链表 值是顺序的
    linkList listEnd;
    listEnd = InitListEnd(&listEnd);
    printAll(&listEnd);

    // 找到元素的位置
    int x = 56678;
    linkList *locate = locateElem(listEnd, x);
    // 这个程序需要注意的是我定义的数组只有9个数, 最后一位是一个0
    printf("\n%d的地址为%p", x, locate);
    // printf("\n值为%d", locate->var);

    // 找到x位置上的结点是
    linkList *number = getElem(listEnd, x);
    // 这个程序需要注意的是我定义的数组只有9个数, 最后一位是一个0
    printf("\n第%d个数的地址为%p", x, number);

    //
    printf("\n");
    linkList *listAdd = insertElem(&listEnd, 2, 10);
    printAll(listAdd);

    deleteElem(&listEnd, 2);
    printAll(&listEnd);

    deleteElemAddress(&listEnd, getElem(listEnd, 4));
    printAll(&listEnd);

    printf("list的长度是%d\n", length(list));
    printf("listEnd的长度是%d\n", length(listEnd));


}
