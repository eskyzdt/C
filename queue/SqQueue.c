#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 队列也是一种操作受限的线性表
 * 只允许在表的一端进行插入,另一端进行删除
 * 入队/进队
 * 出队/离队
 */
/**
 * 注意, 栈和队列是操作受限的线性表,所以不是所有的操作都可以在上面实现
 * 比如, 读取任意位置的数据就是不可以的
 */
/**
 * 判断队列是否为空
 * 如果是顺序存储结构
 * Q.front = Q.rear
 * 判断是否满了
 * front = MAXSIZE
 * 但是这种满是一种假满, 因为很可能出栈了一些元素, 它只是上溢
 *
 */
/**
 * 为了解决上面这种问题, 可以把队列的结构改成循环的,

 循环队列的操作:
   增加一个: (Q.rear + 1) % MAXSIZE 再赋值
   减少一个: Q.front先赋值 再 (Q.front + 1) % MAXSIZE
   小结: 增加或者减少都是 加一操作
   求队列长度 (Q.rear + MAXSIZE - Q.front) % MAXSIZE

   判断队空的条件都是Q.rear = Q.front

 * 判断循环队列是否满可以用三种方式
* 1.  Q.front + 1 = Q.rear
2. 增加一个是否满的flag   flag为1则满 flag为0则没满   (注意: 插入操作导致Q.front == Q.rear时, 把flag置为1, 删除操作....置为0)
3. 增加一个队列大小的size  size为MAXSIZE时满 size为0时为空 (这两种情况下均有Q.front == Q.rear)
一般用第一种

 */





// 链表结构的队列
typedef struct LinkQueue {
    int data;
    struct Linkqueue *next;
} *LinkQueue;

/**
 * 执行initQueue()时
 * MAXSIZE用10会报错, 改成2或者3这种小一点的就不报错了
 *
 * linux上报错
 * Segmentation fault (core dumped)
 *
 * windows上报错
 * 0 [main] a 1117 cygwin_exception::open_stackdumpfile: Dumping stack trace to a.exe.stackdump
 *
 * 原因:
 *    SequenceQueue queue = malloc(sizeof (SequenceQueue));
 *    分配的内存小了
 *    改为
 *       SequenceQueue queue = malloc(sizeof (SequenceQueue) + 40); 即可
 *       给它足够的空间
 */
#define MAXSIZE 10

// 顺序结构的队列
typedef struct SqQueue {
    int data[MAXSIZE];
    int front, rear;
} SqQueue, *SequenceQueue;

// 初始化
SequenceQueue initQueue() {
//    SequenceQueue queue = malloc(sizeof (SequenceQueue) + 40); 和下面的41相等
// 注意用sizeof的里面必须为结构体, 如果写成 sizeof (SequenceQueue) , 求出的结果是指针的长度,而指针的长度永远是1(因为存的是地址)
    SequenceQueue queue = malloc(sizeof(struct SqQueue));
    queue->front = 0;
    queue->rear = 0;
}

bool isEmpty(SequenceQueue queue) {
    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}

// 入队列
bool en_queue(SequenceQueue queue, int var) {
    // 队列满则报错
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        return false;
    }
    // 没满的话把值加进去
    queue->data[queue->rear] = var;
    // 尾指针加一
    queue->rear = (queue->rear + 1) % MAXSIZE;
}

bool de_queue(SequenceQueue queue, int *var) {
    // 出队的时候如果已经空了那么就报错
    if (queue->front == queue->rear) {
        return false;
    }
    // 队首的值赋给指针变量
    *var = queue->data[queue->front];
    // 队首指针加一
    queue->front = (queue->front + 1) % MAXSIZE;
    return true;
}

int getLength(SqQueue queue) {
    return (queue.rear + MAXSIZE - queue.front) % MAXSIZE;
}

bool isMax(SqQueue queue) {
    if (queue.front - queue.rear == 1) {
        return true;
    }
    return false;
}


int main() {
    SequenceQueue queue = initQueue();
    printf("是否为空: %d\n", isEmpty(queue));
    printf("长度是%d\n", getLength(*queue));
    printf("是否已满%d\n", isMax(*queue));
    en_queue(queue, 3);
    printf("是否为空: %d\n", isEmpty(queue));
    int *result = malloc(4);
    de_queue(queue, result);
    printf("result的地址是: %p\n", result);
    printf("result的值是: %d", *result);


}








