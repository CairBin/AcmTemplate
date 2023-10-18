// 堆优化的Prim
#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define int long long int
#define il inline

int n, m;
vector<int> head, nxt, to, we, dis;
typedef struct VD
{
    int v;
    int w;

    bool operator<(const struct VD &x) const
    {
        return this->w < x.w;
    }
    // 重载大于号，让优先队列按权值排序，小的优先
    bool operator>(const struct VD &x) const
    {
        return this->w > x.w;
    }
    bool operator==(const struct VD &x) const
    {
        return this->w == x.w;
    }

} vd;

vector<bool> vis;

void init()
{
    dis.resize(n + 1, INF);
    head.resize(n + 1, -1);
    vis.resize(n + 1, false);
}

void add(int u, int v, int w)
{
    nxt.push_back(head[u]);
    head[u] = to.size();
    to.push_back(v);
    we.push_back(w);
}

// 小根堆,升序排列；不写greater<vd>大根堆，降序排列
priority_queue<vd, vector<vd>, greater<vd>> que;
int prim()
{
    int res = 0;
    dis[1] = 0;
    que.push({1, 0});
    int cnt = 0;
    while (!que.empty())
    {
        if (cnt >= n)
            break;
        auto [v, d] = que.top();
        que.pop();
        if (vis[v])
            continue;
        vis[v] = true;
        ++cnt;
        res += d;
        for (int i = head[v]; ~i; i = nxt[i])
        {
            int v_ = to[i];
            int w_ = we[i];
            if (w_ < dis[v_])
                dis[v_] = w_, que.push({v_, w_});
        }
    }

    if (cnt != n)
        return INF;

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

    if (res && res < INF)
        cout << res << endl;
    else
        cout << "orz" << endl;

    return 0;
}