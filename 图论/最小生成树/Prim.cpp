// 使用优先队列优化的Prim算法

#include <bits/stdc++.h>

using namespace std;

#define int long long int

#define N (int)1e5
#define M 2e5 + 10

typedef struct Edge
{
    int v, w, x;
} edge;

edge e[(int)(M * 2)];
int cnte;
int h[N];

void addEdge(int u, int v, int w)
{
    e[++cnte] = edge{v, w, h[u]};
    h[u] = cnte;
}

typedef struct S
{
    int u, d;
    bool operator<(const S &x) const
    {
        // 距离大就远优先级就低
        return this->d > x.d;
    }
} S;

priority_queue<S> que;
int dis[N];
bool vis[N]; // 存储是否已经被访问过

int res, cnt;
int n, m;

void prim()
{
    memset(dis, 0x3f, sizeof(dis)); // 0x3f十进制1061109567是10^9级别的，通常作为无穷大
    dis[1] = 0;
    que.push({1, 0});
    while (!que.empty())
    {
        if (cnt >= n)
            break;
        int u = que.top().u;
        int d = que.top().d;
        que.pop();

        // 判断是否访问过
        if (vis[u])
            continue;
        vis[u] = 1;
        ++cnt;
        res += d;

        for (int i = h[u]; i; i = e[i].x)
        {
            int v = e[i].v;
            int w = e[i].w;

            if (w < dis[v])
                dis[v] = w, que.push({v, w});
        }
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    prim();
    if (cnt == n)
        cout << res << endl;
    else
        cout << "orz" << endl;

    return 0;
}