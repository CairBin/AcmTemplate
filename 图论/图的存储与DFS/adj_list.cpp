#include <bits/stdc++.h>

using namespace std;

class graph
{
private:
    int n, m;
    vector<bool> vis;

    /*
        邻接表，此处定义虽然与邻接矩阵相同，但是操作不一样
        个人更喜欢用unordered_map来存（如果不要求顺序的话）
    */
    vector<vector<int>> adj;

public:
    graph(int a_n, int a_m)
    {
        n = a_n;
        m = a_m;
        vis.resize(n + 1, false);
        adj.resize(n + 1); // 由此可见邻接矩阵与邻接表的差异在第二个维度
    }

    void addEdge(int u, int v)
    {
        // 此处可判断越界

        adj[u].push_back(v);
    }

    // 如果排序的话可改用二分查询
    bool findEdge(int u, int v)
    {
        // 注意此处i初始为0，与之前模板不一样
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (adj[u][i] == v)
                return true;
        }

        return false;
    }

    void dfs(int u)
    {
        if (vis[u])
            return;
        vis[u] = true;
        for (int i = 0; i < adj[u].size(); i++)
            dfs(adj[u][i]);
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