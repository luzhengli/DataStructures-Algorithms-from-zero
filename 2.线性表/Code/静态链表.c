#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10 // 静态链表最大长度
typedef struct node // 定义静态链表
{
    int data;
    int next; // 游标
} SLinkList[MAXSIZE];

bool InitList(LinkList L);
bool Empty(LinkList L);
bool InsertAfterNode(LNode *p, int e);
bool DeleteNodeAfter(LNode *p);
bool PrintList(LinkList L);
int main()
{
    return 0;
}

bool InitList(LinkList L) // 创建双链表
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = L; // 头结点指向自己
    return true;
}

bool Empty(LinkList L)
{
    return L->next == L;
}

bool InsertAfterNode(LNode *p, LNode *s) // 在某节点p后插入一个结点s
{
    if (p == NULL || s == NULL) // 如果结点不存在 插入失败
    {
        return false;
    }
    // 节点存在 则尝试插入
    s->next = p->next;
    if (p->next != NULL) // 如果p指向的是结点（不是空指针）则需要将其前驱结点指向s
    {
        p->next->prior = s;
    }
    p->next = s;
    s->prior = p;

    return true; // 插入成功的标志
}

bool DeleteNodeAfter(LNode *p) // 删除指定结点q的后继结点（如果有）
{
    if (p == NULL) // 结点p不合法
    {
        return false;
    }
    LNode *q = p->next; // 获取p的后继结点
    if (q == NULL)      // 结点p无后继结点
    {
        return false;
    }

    // 开始删除：
    p->next = q->next;
    if (q->next != NULL) // 如果q的后继结点不是空指针 需要将q结点的后继节点的前驱指针指向p
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}
