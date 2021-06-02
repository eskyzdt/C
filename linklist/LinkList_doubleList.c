#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int array[MAXSIZE] = {23, 123, 554, 678, 9, 34, 237, 56678, 345, 10};

/**
 * *DListPoint 定义一个DNode结构的指针
 */
typedef struct DNode {
    int data;
    struct DNode *prior, *next
} DNode, *DListPoint;

// 带头结点的打印
void printAll(DListPoint list) {
    DListPoint headPoint = list;
    // 如果头结点的指针不为null, 则找第一个结点的指针
    printf("该链表所有的值是:");
    while (headPoint->next != NULL) {
        // 指针移到下一个
        headPoint = headPoint->next;
        printf("%d ", headPoint->data);
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

// 头插法建立
// todo 暂时不懂的问题:
// 这里不用返回值来获取的话, 子函数修改后的内容到了main函数中直接就失效了
// todo 暂时的理解
// 因为:在main函数中声明的是静态内存分配, 静态内存分配是分配在栈中的,而malloc是在堆内存中动态内存分配,

// 上面的暂时理解是正确的, 除此之外, 用void返回也行, 但是得首先在main函数中使用malloc分配一个空间给数据结构
// 这样的话, 在子函数中对其的修改就可以生效了, 参见LineList_LinkList_delete.c 中的init()

DListPoint initList(DListPoint list) {
    // 头结点
    list = (DListPoint) malloc(sizeof(DNode));
    // 头结点的值可以不置为0
    list->data = 0;
    list->next = NULL;
    list->prior = NULL;
    // 双链表和单链表不一样的地方在于,每个结点都需要处理它的前驱, 由于刚开始的时候头结点的下一个结点为NULL, 而NULL是没有前驱结点的
    // 所以如果把第一个结点和其他结点一样去处理, 会导致在查询NULL的前驱时出错
    // 故 第一个结点需要单独处理
    DListPoint node = (DListPoint) malloc(sizeof(DNode));
    // 不要忘记把第一个结点的值也赋上
    node->data = array[0];
    node->next = list->next;
    node->prior = list;
    list->next = node;
    // 循环数组中的元素往链表中插入
    for (int i = 1; i < MAXSIZE; ++i) {
        DListPoint node = (DListPoint) malloc(sizeof(DNode));
        // 赋值
        node->data = array[i];
        // 新结点的后继为原后继
        node->next = list->next;
        // 新结点的前驱为头结点
        node->prior = list;
        // 原结点的前驱结点变为新结点
        if (list->next != NULL)
            list->next->prior = node;
        // 头结点的后继为
        list->next = node;
    }
    printAll(list);
    return list;
}

// 尾插法建立
DListPoint initListEnd(DListPoint list) {
    // 头结点
    list = (DListPoint) malloc(sizeof(DNode));
    list->next = NULL;
    list->prior = NULL;
    // 尾结点
    DListPoint endPoint = (DListPoint) malloc(sizeof(struct DNode));
    endPoint = list;
    int i = 0;
    while (i < MAXSIZE) {
        DListPoint node = malloc(sizeof(struct DNode));
        node->data = array[i];
        // 新增结点指向尾结点
        node->prior = endPoint;
        // 原尾结点的下一个指针指向新的结点
        endPoint->next = node;
        // 移动尾结点到新结点之上
        endPoint = node;
        i++;
    }
    // 把最后一个结点置为NULL
    endPoint->next = NULL;
    printAll(list);
    return list;
}

DListPoint getElem(DNode list, int index) {
    if (index < 0) {
        return NULL;
    }
    int i = 0;
    DListPoint result = &list;
    while (result->next != NULL || i < index) {
        result = result->next;
        i++;
        if (i == index) {
            // 如果有值的话返回一个地址
            return result;
        }
    }
    // 没有就返回一个null
    return NULL;
}

DListPoint locateElem(DNode list, int var) {
    DListPoint node = &list;
    while (node != NULL && var != node->data) {
        node = node->next;
    }
    return node;
}

int length(DNode list) {
    int i = 0;
    DListPoint tem = &list;
    while (tem->next != NULL) {
        tem = tem->next;
        i++;
    }
    return i;
}

void deleteElem(DListPoint list, int i) {
    // 先找到第三个地址
    DListPoint del = getElem(*list, i);
    // 让前一个元素直接指向下一个
    del->prior->next = del->next;
    del->next->prior = del->prior;
    free(del);
}

/**
 *
 * @param list 待插入链表
 * @param addr 需要被插入这个结点之后
 * @param var 需要被插入的值
 */
void insertElem(DListPoint addr, int var) {
    DListPoint node = (DListPoint) malloc(sizeof(DListPoint));
    node->data = var;
    node->next = addr->next;
    node->prior = addr;
    node->next->prior = node;
    addr->next = node;
}

// main
void main() {
    // 这样声明之后是在栈内存中
    DListPoint list;
    list = initList(list);
    printAll(list);
    // initListEnd(&list);
    DListPoint node = getElem(*list, 3);
    printf("第三个数的值是%d\n", node->data);

    int length2 = length(*list);
    printf("length is%d\n", length2);

    DListPoint elemAddr = locateElem(*list, 678);
    printf("地址为%p", elemAddr);

    // 在elemAddr的位置之后插入一个
    insertElem(elemAddr, 999);
    printAll(list);
// 空间分配:
    // 顺序存储: 静态分配的时候, 如果空间已经满了,那么再插入数据会报错, 所以要分配一个合适大小的空间
    // 但是如果分配的过大会造成空间的浪费, 分配的过小又会内存溢出.
    // 如果是动态分配, 在空间满的时候需要移动大量的元素, 导致操作效率降低, 而且若内存中没有更大的连续存储空间,会导致分配失败.
    // 链式存储: 需要的时候分配内存空间即可, 只要内存还有空间, 就可以分配, 操作灵活高效
    // 删除第三个

    // 选择的标准: 1.基于存储的考虑, 如果预先大概知道需要的存储空间, 那么就可以用顺序存储, 如果不知道, 就用链式存储
    //          2. 基于数据结构的考虑,所有高级语言都有数组结构, 该数据结构比较简单, 而链表的数据结构要稍复杂
    //          3. 基于运算的考虑, 如果增加和删除操作多, 用链表, 如果查询的操作多,用顺序表
    deleteElem(list, 3);
    printAll(list);

}

