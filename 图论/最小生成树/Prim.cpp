#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define INF INT_MAX

// Chain Forward Star存储
vector<int> head, nxt, to, we, dis;
vector<bool> vis;
int n, m;

void init()
{
    head.resize(n + 1, -1);
    vis.resize(n + 1, false);
    dis.resize(n + 1, INF);
}

void add(int u, int v, int w)
{
    nxt.push_back(head[u]);
    head[u] = to.size();
    to.push_back(v);
    we.push_back(w);
}

int prim()
{
    int res = 0;
    int now = 1;

    for (int k = 1; k < n; k++)
    {
        for (int i = head[now]; ~i; i = nxt[i])
        {
            int v = to[i];
            if (!vis[v] && dis[v] > we[i])
                dis[v] = we[i];
        }

        int mins = INF;
        vis[now] = true;

        for (int i = 1; i <= n; i++)
            if (!vis[i] && mins > dis[i])
            {
                mins = dis[i];
                now = i;
            }

        res += mins;
    }

    return res;
}

// luogu 3366
signed main()
{
    cin >> n >> m;
    init();
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    int res = prim();

    //  如果图不连通至少为INF
    if (res && res < INF)
        cout << res << endl;
    else
        cout << "orz" << endl;

    return 0;
}