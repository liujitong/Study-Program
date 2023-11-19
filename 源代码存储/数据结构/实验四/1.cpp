#include<stdio.h>
#define N 20//顶点最大个数
#define TRUE 1
#define FALSE 0
int visited[N];    
typedef struct    /*队列的定义*/
{
    int data[N];
    int front,rear;
}queue;
typedef struct    /*图的邻接矩阵*/
{
    int vexnum,arcnum;//顶点数和边数
    char vexs[N];
    int arcs[N][N];
}
graph;

void createGraph(graph *g);  /*建立一个无向图的邻接矩阵*/
void dfs(int i,graph *g);    /*从第i个顶点出发深度优先搜索*/
void tdfs(graph *g);          /*深度优先搜索整个图*/
void bfs(int k,graph *g);    /*从第k个顶点广度优先搜索*/
void tbfs(graph *g);          /*广度优先搜索整个图*/
void init_visit();            /*初始化访问标识数组*/

void createGraph(graph *g)   /*建立一个无向图的邻接矩阵*/
{   int i,j;
    char v;
    g->vexnum=0;
    g->arcnum=0;
    i=0;
    printf("输入顶点序列(以#结束)：\n");
    while((v=getchar())!='#')
    {
        g->vexs[i]=v;        /*读入顶点信息*/
        i++;
    }
    g->vexnum=i;             /*顶点数目*/
    for(i=0;i<g->vexnum;i++) /*邻接矩阵初始化*/
        for(j=0;j<g->vexnum;j++)
            g->arcs[i][j]=0;
    printf("输入边的信息：\n");
    scanf("%d,%d",&i,&j);  /*读入边i,j*/
    while(i!=-1)              /*读入i,j为－1时结束*/
    {
        g->arcs[i][j]=1;
        g->arcs[j][i]=1;
        scanf("%d,%d",&i,&j);
    }
}

void dfs(int i,graph *g) /*从第i个顶点出发深度优先搜索*/
{
    int j;
    printf("%c",g->vexs[i]);
    visited[i]=TRUE;
    for(j=0;j<g->vexnum;j++)
        if((g->arcs[i][j]==1)&&(!visited[j]))
            dfs(j,g);
}

void tdfs(graph *g)      /*深度优先搜索整个图*/
{
    int i;
    printf("\n从顶点%C开始深度优先搜索序列：",g->vexs[0]);
    for(i=0;i<g->vexnum;i++)
        if(visited[i]!=TRUE)
            dfs(i,g);
}

void bfs(int k,graph *g)  /*从第k个顶点广度优先搜索*/
{
    int i,j;
    queue qlist,*q;
    q=&qlist;
    q->rear=0;
    q->front=0;
    printf("%c",g->vexs[k]);
    visited[k]=TRUE;
    q->data[q->rear]=k;
    q->rear=(q->rear+1)%N;
    while(q->rear!=q->front)
    {
        i=q->data[q->front];
        q->front=(q->front+1)%N;
        for(j=0;j<g->vexnum;j++)
            if((g->arcs[i][j]==1)&&(!visited[j]))
            {
                printf("%c",g->vexs[j]);
                visited[j]=TRUE;
                q->data[q->rear]=j;
                q->rear=(q->rear+1)%N;
            }
    }
}

void tbfs(graph *g) /*广度优先搜索整个图*/
{
    int i;
    printf("\n从顶点%C开始广度优先搜索序列：",g->vexs[0]);
    for(i=0;i<g->vexnum;i++)
        if(visited[i]!=TRUE)
            bfs(i,g);
}

void init_visit()   /*初始化访问标识数组*/
{
    int i;
    for(i=0;i<N;i++)
        visited[i]=FALSE;
}

int main()
{
    graph ga;
    int i,j;
    createGraph(&ga);
    printf("无向图的邻接矩阵：\n");
    for(i=0;i<ga.vexnum;i++)
    {
        for(j=0;j<ga.vexnum;j++)
            printf("%3d",ga.arcs[i][j]);
        printf("\n");
    }
    init_visit();
    tdfs(&ga);
    init_visit();
    tbfs(&ga);
    return 0;
}
