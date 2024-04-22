#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 100; //定义最大顶点数
const int INF = INT_MAX; //定义极大值

struct Graph {
    int vexnum, arcnum; //顶点数和边数
    char vexs[MAXN];//顶点信息
    int arcs[MAXN][MAXN];//邻接矩阵
};

//深度优先搜索
vector<bool> visited(MAXN, false);//标记顶点是否被访问过

void dfs(int i, Graph* g) {
    cout << g->vexs[i];//输出顶点信息
    visited[i] = true;//标记顶点i已被访问
    for (int j = 0; j < g->vexnum; j++) {//遍历所有顶点
        if (g->arcs[i][j] == 1 && !visited[j]) {//如果顶点i与顶点j相邻且顶点j未被访问
            dfs(j, g);//递归访问顶点j
        }
    }
}

void tdfs(Graph* g) {//深度优先搜索
    cout << "\n从顶点开始的DFS序列" << g->vexs[0] << ": ";
    for (int i = 0; i < g->vexnum; i++) {
        if (!visited[i]) {
            dfs(i, g);
        }
    }
}

//广度优先搜索
void bfs(int k, Graph* g) {
    queue<int> que;//定义队列
    cout << g->vexs[k];//输出顶点信息
    visited[k] = true;//标记顶点k已被访问
    que.push(k);//将顶点k入队
    while (!que.empty()) {//队列不为空
        int i = que.front();//取队首元素
        que.pop();//出队
        for (int j = 0; j < g->vexnum; j++) {//遍历所有顶点/
            if (g->arcs[i][j] == 1 && !visited[j]) {//如果顶点i与顶点j相邻且顶点j未被访问
                cout << g->vexs[j];//输出顶点信息
                visited[j] = true;//标记顶点j已被访问
                que.push(j);//将顶点j入队
            }
        }
    }
}

void tbfs(Graph* g) {//广度优先搜索
    cout << "\n从顶点开始的BFS序列" << g->vexs[0] << ": ";
    for (int i = 0; i < g->vexnum; i++) {
        if (!visited[i]) {
            bfs(i, g);
        }
    }

}

int main() {
    Graph g;
    cout << "输入图的总顶点数和总边数:";
    cin >> g.vexnum >> g.arcnum;//输入总顶点数和总边数
    cout << "输入顶点信息:\n";//输入顶点信息
    for (int i = 0; i < g.vexnum; i++) {//输入顶点信息
        cin >> g.vexs[i];//输入顶点信息
    }
    for (int i = 0; i < g.vexnum; i++) {//初始化
        for (int j = 0; j < g.vexnum; j++) {
            g.arcs[i][j] = 0;
        }
    }
    cout << "输入相连结点\n";
    for (int i = 0; i < g.arcnum; i++) {//构造邻接矩阵
        char v1, v2;//表示v1和v2相连接
        cin >> v1 >> v2;//输入相连结点
        int k = 0, l = 0;//找到v1和v2在图G中的位置
        while (g.vexs[k] != v1) {//找到v1在图G中的位置
            k++;
        }
        while (g.vexs[l] != v2) {//找到v2在图G中的位置
            l++;
        }
        g.arcs[k][l] = g.arcs[l][k] = 1;//构造邻接矩阵
    }
    cout << "邻接矩阵如下:\n";
    for (int i = 0; i < g.vexnum; i++) {//输出邻接矩阵
        for (int j = 0; j < g.vexnum; j++) {
            cout << g.arcs[i][j] << " ";
        }
        cout << endl;
    }
    cout << "深度优先搜索:\n";
    visited.assign(MAXN, false);//初始化
    tdfs(&g);//深度优先搜索
    cout << "\n广度优先搜索:\n";
    visited.assign(MAXN, false);
    tbfs(&g);
    return 0;
}