#include <stdio.h>
typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 左右线索标志
} ThreadNode, *ThreadTree;
ThreadNode *pre = NULL; // 遍历二叉树时指向当前访问结点的前驱结点

void CreateInThread(ThreadTree T)
{
    pre = NULL;    // pre指针初始化
    if (T != NULL) // 对于非空二叉树才可以线索化
    {
        InThread(T); // 中序线索化二叉树
        if (pre->rchild == NULL)
        {
            pre->rtag = 1; // 处理最后一个结点
        }
    }
}

void InThread(ThreadTree T) // 二叉树的中序线索化
{
    if (T != NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void visit(ThreadNode *q)
{
    if (q->lchild == NULL) // 找到当前结点的前驱结点
    {
        q->lchild = pre;
        q->ltag = 1; // 线索化标志置1 表示已经线索化
    }
    if (pre != NULL && pre->rchild == NULL) // 找到当前结点的前驱结点的后继节点
    {
        pre->rchild = q;
        pre->ltag = 1;
    }
    pre = q;
}