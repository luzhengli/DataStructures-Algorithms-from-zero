#include<stdio.h>
typedef struct AVLNode{
    int data; // 数据域
    int balance; // 平衡因子
    struct AVLNode *lchild, *rchild;
} AVLNode, *AVLTree;
