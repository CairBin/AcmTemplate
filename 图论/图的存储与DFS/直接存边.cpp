#include <bits/stdc++.h>

using namespace std;

class graph
{
private:
    int n; // vex个数
    int m; // 边数
    int tot;

private:
    typedef struct Edge
    {
        int u, v;
    } edge;

private:
    vector<edge> e;     // 存放边
    vector<bool> isVis; // 判断是否访问过

public:
    graph(int vexNum, int edgeNum)
    {
        this->n = vexNum;
        this->m = edgeNum;

        this->isVis.resize(n + 1, false);
        this->e.resize(m + 1);
        this->tot = 0;
    }

    void addEdge(int u, int v)
    {
        if (tot >= m + 1)
            return;

        this->e[++tot] = {u, v};
    }

    bool findEdge(int u, int v)
    {
        for (int i = 1; i <= m; i++)
        {
            // cout << e[i].u << " " << e[i].v << endl;
            if (e[i].u == u && e[i].v == v)
                return true;
        }

        return false;
    }

    // 从u结点开始dfs
    void dfs(int u)
    {
        if (isVis[u])
            return;
        isVis[u] = true;

        for (int i = 1; i <= m; i++)
        {
            if (e[i].u == u)
            {
                dfs(e[i].v);
            }
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