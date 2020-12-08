#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next; // 这里不能使用 LNode *next;
} LNode, *LinkList;

bool InitList(LinkList L);
bool InsertAfterNode(LNode *p, int e);
bool PrintList(LinkList L);
int main()
{
    LinkList L;

    if (InitList(L)) // 创建单链表 如果创建成功 则进行10次头插操作
    {
        for (int i = 0; i < 10; i++)
        {
            InsertAfterNode(L, i);
        }
    }

    if (PrintList(L))
    {
        puts("\nHave printed LinkedList.");
    }
    // PrintList(L); // 打印查看结果

    return 0;
}

bool InitList(LinkList L)
{
    // 创建头结点
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL; // 设置头结点的next指向NULL
    return true;    // 成功创建返回标志
}

bool InsertAfterNode(LNode *p, int e) // 在某节点后插入一个节点
{
    if (p == NULL) // 如果结点不存在 插入失败
    {
        return false;
    }
    else // 节点存在 则尝试插入
    {
        LNode *NewNode = (LNode *)malloc(sizeof(LNode));
        if (NewNode == NULL)
        {
            return false;
        }
        NewNode->data = e;
        NewNode->next = p->next;
        p->next = NewNode;
    }
    return true; // 插入成功的标志
}

bool PrintList(LinkList L) // 遍历打印单链表的所有元素
{
    if (L->next == NULL)
    {
        return false;
    }
    else
    {
        for (L = L->next; L; L = L->next)
        {
            printf("%d ", L->data);
        }
        return true;
    }
}
