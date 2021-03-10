#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int from, to, flow, cap;
    Edge(int x, int y, int f, int c) : from(x), to(y), flow(f), cap(c) {}
};

vector<Edge> edges;
vector<int> G[maxn];
int cur[maxn], d[maxn];
int S,T;
int cnt;

inline void addedge(int from, int to, int cap)
{
    edges.push_back(Edge(from, to, 0, cap));
    edges.push_back(Edge(to, from, 0, 0));
    int m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}

int dfs(int u, int a)
{
    if (u == T || a == 0)
    {
        return a;
    }
    int flow = 0, f;
    for (int &i = cur[u]; i < G[u].size(); i++)
    {
        Edge &e = edges[G[u][i]];
        if (d[e.to] > d[u] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
        {
            flow += f;
            e.flow += f;
            edges[G[u][i] ^ 1].flow -= f;
            a -= f;
            if (a == 0)
            {
                break;
            }
        }
    }
    if (a)
    {
        d[u] = -1;
    }
    return flow;
}

bool bfs()
{
    memset(d, -1, (T + 1) * sizeof(int));
    queue<int> q;
    q.push(S);
    d[S] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge &e = edges[G[u][i]];
            if (d[e.to] == -1 && e.cap > e.flow)
            {
                d[e.to] = d[u] + 1;
                q.push(e.to);
            }
        }
    }
    return d[T] != -1;
}

int max_flow()
{
    int ans = 0;
    while (bfs())
    {
        memset(cur, 0, (T+1)*sizeof(int));
        ans += dfs(S, INF);
    }
    return ans;
}