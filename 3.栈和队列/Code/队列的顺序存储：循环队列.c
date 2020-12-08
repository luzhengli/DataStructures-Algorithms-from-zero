#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int front, rear; // 队头和队尾指针
} SqQueue;

void InitQueue(SqQueue Q);
bool isEmpty(SqQueue Q);
bool isFull(SqQueue Q);
bool EnQueue(SqQueue Q, int x);
int main(int argc, char const *argv[])
{

    return 0;
}

void InitQueue(SqQueue Q) // 队列初始化
{
    Q.front = Q.rear = 0; // 开始队头和队尾都指向0
}

bool isEmpty(SqQueue Q) // 判断队列是否为空
{
    return Q.rear == Q.front; // 如果队头==队尾 则表示为空
}

bool isFull(SqQueue Q) // 判断队列是否满
{
    return ((Q.rear + 1) % MaxSize) == Q.front;
}

bool EnQueue(SqQueue Q, int x) // 入队
{
    if (isFull(Q)) // 如果队列已满则入队失败
    {
        return false;
    }
    Q.data[Q.rear] = x;              // 把元素插入到队尾所指的位置
    Q.rear = (Q.rear + 1) % MaxSize; // 队尾指针后移（这里考虑到出队后数组前端产生空间可以继续入队的情况 这种队列叫做循环队列）
    return true;
}

bool Dequeue(SqQueue Q, int *x) // 出队
{
    if (isEmpty(Q))
    {
        return false;
    }
    *x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
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