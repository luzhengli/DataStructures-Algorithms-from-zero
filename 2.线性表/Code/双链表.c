#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node // 定义双链表的结点
{
    int data;
    struct node *prior, *next;
} DNode, *DLinkList;

bool InitList(DLinkList L);
bool Empty(DLinkList L);
bool InsertAfterNode(DNode *p, int e);
bool DeleteNodeAfter(DNode *p);
bool PrintList(DLinkList L);
int main()
{
    return 0;
}

bool InitList(DLinkList L) // 创建双链表
{
    // 创建头结点
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = NULL; // 头结点的前驱结点永远为NULL
    L->next = NULL;  // 头结点的后继结点暂时未NULL
    return true;     // 成功创建返回标志
}

bool Empty(DLinkList L)
{
    return L->next == NULL;
}

bool InsertAfterNode(DNode *p, DNode *s) // 在某节点p后插入一个结点s
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

bool DeleteNodeAfter(DNode *p) // 删除指定结点q的后继结点（如果有）
{
    if (p == NULL) // 结点p不合法
    {
        return false;
    }
    DNode *q = p->next; // 获取p的后继结点
    if (q == NULL) // 结点p无后继结点
    {   
        return false;
    }
    
    // 开始删除：
    p->next = q->next;
    if(q->next != NULL) // 如果q的后继结点不是空指针 需要将q结点的后继节点的前驱指针指向p
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}
