#include <stdio.h>
#define MaxVertexNum 100
typedef struct ArcNode // 边/弧
{
    int adjvex;           // 边/弧指向哪一个顶点
    struct ArcNode *next; // 指向下一条弧的指针
    //  边权值
} ArcNode;
 
typedef struct VNode // 顶点
{
    char data;      // 顶点信息
    ArcNode *first; // 第一条边/弧
} VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum; // 顶点数，边数
} ALGraph;

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
