#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m;
vector<bool> vis;
vector<int> head, nxt, to, w, dis;

void init()
{
    vis.resize(n + 1, false);
    head.resize(n + 1, -1);
    dis.resize(n + 1, -1);
}

void add(int u, int v, int we)
{
    nxt.push_back(head[u]);
    head[u] = to.size();
    to.push_back(v);
    w.push_back(we);
}

int prim()
{
    int res = 0;
    dis[1] = 0;
    //-1为无穷大
    for (int i = head[1]; i != -1; i = nxt[i])
        dis[to[i]] = dis[to[i]] == -1 ? w[i] : min(dis[to[i]], w[i]);
    // printf("dis2:%lld\n", dis[2]);
    for (int i = 0, now = 1; i < n; i++)
    {
        int mins = -1;
        vis[now] = 1;
        // printf("now: %lld dis: %lld\ndis[2]: %lld\n", now, dis[now], dis[2]);
        //   从与当前树相连的所有终点里找距离最小的点
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (mins == -1 || mins > dis[j]))
                mins = dis[j], now = j;
        }

        // cout << mins << endl;
        if (mins >= 0)
            res += mins;

        // 建立与刚加入点相连的结点的距离
        // 注意只是建立周围结点的距离关系而不是下次连接结点时一定要从与这个相连结点来找
        for (int j = head[now]; j != -1; j = nxt[j])
        {
            int v = to[j];
            if ((dis[v] > w[j] || dis[v] == -1) && !vis[v])
                dis[v] = w[j];
        }
    }

    return res;
}

signed main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    int res = prim();
    bool flag = true;
    for (int i = 1; i < vis.size(); i++)
        if (!vis[i])
        {
            flag = false;
            break;
        }

    if (flag)
        cout << res << endl;
    else
        cout << "orz" << endl;

    return 0;
}