#include <stdio.h>
#include <stdbool.h>

#define MaxSize 50

typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *S) // 初始化
{
    S->top = -1;
}

bool isEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack *S, char x) // 入栈
{
    if (S->top == MaxSize - 1) // 栈满
    {
        return false;
    }
    (S->top)++;           // 栈顶指针加1
    S->data[S->top] = x; // 元素入栈
    return true;
}

bool Pop(SqStack *S, char *x) // 出栈 把元素返回给x
{
    if (S->top == -1) // 栈空
    {
        return false;
    }
    (*x) = S->data[S->top];
    (S->top)--;
    return true;
}

bool bracketCheck(char str[]);
int main(int argc, char const *argv[])
{
    char s[] = "({})[[({})]]";

    if (bracketCheck(s))
    {
        printf("Check successful");
    }
    else
    {
        printf("Check failing");
    }

    return 0;
}

