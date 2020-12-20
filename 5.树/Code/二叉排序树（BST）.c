#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

int main(int argc, char const *argv[])
{

    return 0;
}

BSTNode *BSTSearch(BSTree T, int key) // BST非递归查找
{
    while (T != NULL && key != T->data) // 如果树为空或者根节点就是目标值 停止查找
    {
        if (T->data > key)
        {
            T = T->rchild;
        }
        else
        {
            T = T->lchild;
        }
    }
    return T;
}

BSTNode *BSTSearch2(BSTree T, int key) // BST递归查找
{
    if (T == NULL)
    {
        return NULL;
    }
    if (T->data == key)
    {
        return T;
    }
    else if (T->data < key)
    {
        return BSTSearch2(T->lchild, key);
    }
    else
    {
        return BSTSearch2(T->rchild, key);
    }
}

bool BSTInsert(BSTree T, int key) // BST插入操作 递归实现
{
    if (T == NULL) // 树为空 插入结点
    {
        T = (BSTNode *)malloc(sizeof(BSTNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if (key == T->data) // 出现相同的数据 插入操作失败
    {
        return 0;
    }
    else if (key < T->data) // 在左子树拆入
    {
        return BSTInsert(T->lchild, key);
    }
    else
    {
        return BSTInsert(T->rchild, key); // 在右子树插入
    }
}