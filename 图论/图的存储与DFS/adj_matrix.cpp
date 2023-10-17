#include <bits/stdc++.h>

using namespace std;

class graph
{
private:
    int n; // 结点数
    int m; // 边数

    vector<bool> isVis;      // 是否被访问过
    vector<vector<int>> adj; // 邻接矩阵

public:
    graph(int vexNum, int edgeNum)
    {
        this->n = vexNum;
        this->m = edgeNum;
        isVis.resize(n + 1, false);
        adj.resize(n + 1, vector<int>(n + 1, 0)); // n*n的邻接矩阵
    }
    void addEdge(int u, int v)
    {
        if (u > n || v > n)
        {
            // debug信息，一般来讲acm给的是规范数据该信息不会输出
            // 这有助于代码调试，而且不用担心输出导致结果报错
            cout << "越界" << endl;
            return;
        }

        this->adj[u][v] = 1;
        // 无向图可取消下面的注释或者每次输入 u,v之后再输入v,u
        // this->adi[v][u] = 1;
    }

    bool findEdge(int u, int v)
    {
        if (u > n || v > n)
            return false;
        return adj[u][v];
    }

    void dfs(int u)
    {
        if (isVis[u])
            return;
        isVis[u] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (adj[u][i]) // 一定要判断是否存在这个结点
                dfs(i);
        }
    }
};

signed main()
{
    int n, m;
    cin >> n >> m;

    graph g(n, m);
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << g.findEdge(1, 2)
         << endl;
    return 0;
}