#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100; // 最大顶点数
const int INF = 10086; // 极大值
typedef struct Mgraph
{
    char vexs[MAXN]; // 顶点表
    int arcs[MAXN][MAXN]; // 邻接矩阵
    int vexnum; // 图的当前点数
    int arcnum; // 图的当前边数
}AMGraph; // 邻接矩阵表示图
// Kruskal算法的边
struct Edge
{
    char head;//最小边在U中的那个顶点
    char tail;//最小边上的权值
    int weight;
}edge[MAXN];//辅助数组
int LocateVex(AMGraph* G, char v) // 找到结点V在图G中的位置 即下标
{
    for (int i = 0; i < G->vexnum; i++)//查找v在图G中的位置
    {
        if (G->vexs[i] == v)
        return i;
    }
    cout << "没找到" << endl;
    return 0;
}
void CreatAMG(AMGraph* G)//邻接矩阵表示法创建无向网
{
    cout << "请输入图的总顶点数与总边数: ";//输入总顶点数 总边数
    cin >> G->vexnum >> G->arcnum;//输入总顶点数 总边数
    cout << "输入点的信息: ";//输入顶点信息
    for (int i = 0; i < G->vexnum; i++)//输入顶点信息
        cin >> G->vexs[i];
    for (int i = 0; i < G->vexnum; i++)//初始化
    for (int j = 0; j < G->vexnum; j++)
        G->arcs[i][j] = INF;
    char v1, v2; // 相连结点
    int w; // 权值
    cout << "输入相连结点及边的权值：" << endl;
    for (int k = 0; k < G->arcnum; k++)//构造邻接矩阵
    {
        cin >> v1 >> v2 >> w; // 表示v1和v2相连接
        edge[k] = { v1,v2,w };
        int i = LocateVex(G, v1);//找到v1在图G中的位置
        int j = LocateVex(G, v2);//找到v2在图G中的位置
        G->arcs[i][j] = G->arcs[j][i] = w;
    }
    cout << "邻接矩阵如下：" << endl;//输出邻接矩阵
    for (int i = 0; i < G->vexnum; i++)//输出邻接矩阵
    {
    for (int j = 0; j < G->vexnum; j++)
        cout << G->arcs[i][j] << " ";//输出邻接矩阵
        cout << "\n";
    }
    return;
}
// Kruskal算法
int parent[MAXN]; // 并查集数组
// 查找根节点
int find(int x)
{
    if (parent[x] != x)
    {
    parent[x] = find(parent[x]); // 路径压缩
    }
    return parent[x];
}
// 合并两个集合
void unionSets(int x, int y)
{
    int rootX = find(x);//查找根节点
    int rootY = find(y);//查找根节点
    if (rootX != rootY)
    {
    parent[rootX] = rootY;
    }
}
bool cmp(struct Edge a, struct Edge b)
{
    return a.weight < b.weight;
}
void miniSpanTree_Krusal(AMGraph* G, char u)
{
    sort(edge, edge + G->arcnum, cmp); // 按权重排序边
// 初始化并查集
    for (int i = 0; i < G->vexnum; i++)//初始化并查集
    {
        parent[i] = i;
    }
    cout << "最小生成树如下（Kruskal）：" << endl;
    int count = 0; // 记录已加入最小生成树的边的数量
    int totalCost = 0; // 记录最小生成树的总权重
    for (const auto& edg : edge)
    {
        int v1 = LocateVex(G, edg.head);
        int v2 = LocateVex(G, edg.tail);
        // 检查是否形成回路
        if (find(v1) != find(v2))
        {
            unionSets(v1, v2); // 合并集合
            count++;
            totalCost += edg.weight;
            cout << edg.head << "--" << edg.tail << "(" << edg.weight << ")" << endl; // 输出此边
            if (count == G->vexnum - 1) break; // 最小生成树已经形成
        }
    }
    if (count < G->vexnum - 1)
    cout << "图不是连通图，没有最小生成树" << endl;
    else
    cout << "最小生成树的权重（Kruskal）：" << totalCost << endl;
}
int main()
{
    AMGraph G;
    CreatAMG(&G);
    miniSpanTree_Krusal(&G, 'A');
    return 0;
}