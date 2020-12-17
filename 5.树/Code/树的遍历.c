#include <stdio.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

void visit()
{
}

void PreOrder(BiTree T) // 前序遍历
{
    if (T != NULL)
    {
        visit(T); 
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T) // 中序遍历
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) // 后序遍历
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
