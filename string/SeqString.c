//
// Created by Administrator on 3/24/2021.
//
/**
 * 类似线性表的顺序存储结构的
 */
#include <stdbool.h>

#define MAXSIZE 20

// 1. 定长顺序存储表示
// 定长顺序存储结构
// 有两种方式, 一个是在结尾处存储一个结束标记符\0, 这个字符不算在长度内
// 但是会占用一个字符空间
// , 另一个方法是增加一个字段length用于存储长度,这里我用的是第二种
typedef struct {
    int length;
    // 在初始化,插入,连接等操作中, 有可能超过定义的长度, 超过定义的这个长度的串会被截断,
    // 如果不想被截断, 只能不限定串的最大长度, 即采用动态分配的方式
    char data[MAXSIZE];
} SString;

// 2. 堆分配存储表示
// C语言中有一个叫堆的自由存储区, malloc和free可以操作这部分空间, 使用malloc时会开辟一部分存储空间
// 返回一个指针, 指向这部分空间的起始地址, 作为串的基地址, 如果分配失败, 会返回一个NULL, 已分配的空间可以free()掉
// 我们定义结构可以按如下所示定义
typedef struct {
    char *ch;
    int length;
} HString;
// 上面ch即是分配出来的起始地址(又叫基地址)的指针
// length是串的长度, 根据起始地址的指针和长度, 可以遍历所有数据

// 3.块链存储表示
// 这种是类似线性表的链式存储结构, 每个结点可以存储单个字符, 也可以存储多个字符
// 每个结点被称为块, 整个链表被称为块链结构, 每个块均有一个指向下一个块的指针, 最后一个块如果没有存满, 通常用#补全.


// 基本操作1
void StrAssign(HString *Str, char a[]) {}

// 基本操作2 这里用-1,0,1来判断大小
int strCompare(HString a, HString b) {}

// 基本操作3
int strLength(HString str) {}

// 基本操作4
void concat(HString *result, HString a, HString b) {}

// 基本操作5
void subString(HString *str, HString var, int pos, int length) {}

HString init() {}

void StrCopy(HString *Str, HString copy) {}

bool deleteStr(HString *str) {}

bool clearStr(HString *str) {}

bool StrEmpty(HString str) {}

int Index(HString a, HString b) {}


int index(SString a, SString b) {
    int i = 1, j = 1;
    while (i <= a.length && j <= b.length) {
        if (a.data[i] == b.data[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > b.length) {
        return i - b.length;
    } else {
        return 0;
    }
}

int main() {

};


// next[q] = k 意味着在q之前的位置, 存在长度为k的相等的前缀和后缀
// 如果str[q] = pattern[q] 则 next[q+1] = k + 1




































