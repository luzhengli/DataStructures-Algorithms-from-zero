#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10
typedef struct node
{
    int data;
    struct node *next;
} LinkNode;

typedef struct // 链式队列
{
    LinkNode *front, *rear; // 队头和队尾指针
} LinkQueue;

void InitQueue(SqQueue Q);
bool isEmpty(SqQueue Q);
bool isFull(SqQueue Q);
bool EnQueue(SqQueue Q, int x);
int main(int argc, char const *argv[])
{

    return 0;
}

void InitQueue(LinkQueue Q) // 队列初始化
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q) // 判断队列是否为空
{
    return Q.front->next == NULL;
}

bool EnQueue(LinkQueue Q, int x) // 入队
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

bool Dequeue(LinkQueue Q, int *x) // 出队
{
    if (isEmpty(Q))
    {
        return false;
    }
    LinkNode *p = Q.front->next; // 准备指针p 指向待删除的结点
    *x = p->data;                // 返回出队的元素
    Q.front->next = p->next;
    if (Q.rear == p) // 如果p是最后一个结点 出队后队列为空
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

bool GetHead(SqQueue Q, int *x) // 查询队头元素
{
    if (isEmpty(Q))
    {
        return false;
    }
    *x = Q.data[Q.front];
    return true;
}

bool GetLength(SqQueue Q, int len) // 获取队列的元素个数/队列长度
{
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}