#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode
{
    int data;
    LNode *next;
} LNode, *LinkList;

bool InitList(LinkList L);
bool InsertAfterNode(LNode *p, int e);
int main()
{
    LNode *p = (LNode *)malloc(sizeof(LNode)); // LNode *p 可用 LinkList p 代替 这样可读性会更强(这种表示强调p是链表)

    return 0;
}

bool InitList(LinkList L)
{
    
}

bool InsertAfterNode(LNode *p, int e)
{

}