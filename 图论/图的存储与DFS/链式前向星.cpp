// 链式前向星实际上就是一种静态的邻接表
#include <bits/stdc++.h>

using namespace std;

class graph
{
private:
    int n, m;
    vector<bool> vis;
    vector<int> head, // 以i为起点，对应最后一条边的编号
        nxt,          // 与当前边起点相同的上一条边的编号
        to;           // 终点

public:
    graph(int an, int am)
    {
        n = an;
        m = am;
        vis.resize(n + 1, false);
        head.resize(n + 1, -1);
    }

    // 可以看做以起点序号为下表的桶，头插对应的终点信息结点
    void add(int u, int v)
    {
        nxt.push_back(head[u]); // 与u相同起点的上一条边
        head[u] = to.size();
        to.push_back(v);
    }

    bool find(int u, int v)
    {
        for (int i = head[u]; i != -1; i = head[i])
            if (to[i] == v)
                return true;
        return false;
    }

    void dfs(int u)
    {
        if (vis[u])
            return;
        vis[u] = true;
        for (int i = head[u]; i != -1; i = head[i])
            dfs(to[i]);
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
        g.add(u, v);
    }

    cout << g.find(1, 2)
         << endl;

    return 0;
}