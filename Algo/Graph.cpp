#include <bits/stdc++.h>

#if __has_include("../../Util/debug.h")
#include "../../Util/debug.h"
#endif

using namespace std;

const double EPS = 1e-9;
const int INF = INT_MAX / 4;
const unsigned long long MOD = 1e9 + 7;
#define TAM 1e6

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ull unsigned long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>

#define mp make_pair

#define pb push_back
#define sz size

#define all(x) x.begin(), x.end()

struct Edge
{
    int w, dst;
    Edge(int _dst, int _w) : w(_w), dst(_dst) {}
};

#define ve vector<Edge>
#define Graph vector<ve>

ostream &operator<<(ostream &os, const Edge &e)
{
    os << "[dst: " << e.dst << ", w: " << e.w << "]";
    return os;
}

Graph adjs;
vi marc;

void dfs(int vertex)
{
    marc[vertex] = true;
    for (int i = 0; i < adjs.size(); i++)
        if (!marc[i])
            dfs(adjs[vertex][i].dst);
}

void bfs(int vertex)
{
    queue<int> q;
    q.push(vertex);
    marc[vertex] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (Edge edge : adjs[current])
        {
            int dst = edge.dst;
            if (marc[dst] == INF)
            {
                q.push(dst);
                marc[dst] = marc[current] + 1;
            }
        }
    }
}

void dijikstra(int vertex)
{
    set<int> q;
    q.insert(vertex);
    marc[vertex] = 0;

    while (!q.empty())
    {
        int current = *q.begin();
        q.erase(current);

        for (auto edge : adjs[current])
        {
            int dst = edge.dst;
            if (marc[dst] == INF)
            {
                q.insert(dst);
                marc[dst] = marc[current] + 1;
            }
        }
    }
}

vvi floyd()
{
    vvi dist = vvi(adjs.size(), vi(adjs.size(), INF));
    print('a');

    for (int i = 0; i < adjs.size(); i++)
    {
        dist[i][i] = 0;
        for (int j = 0; j < adjs[i].size(); j++)
            dist[i][adjs[i][j].dst] = adjs[i][j].w;
    }
    debug(dist);
    for (int i = 0; i < adjs.size(); i++)
        for (int j = 0; j < adjs.size(); j++)
            for (int k = 0; k < adjs.size(); k++)
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]);

    return dist;
}

bool negativeCycle(vvi dist)
{
    for (int i = 0; i < dist.size(); i++)
        if (dist[i][i] < 0)
            return true;

    return false;
}

int kosaraju(){
    dfs_kosaraju()}

    vector < vector

    queue<int> q_kosaraju;

Graph transpose(Graph &g)
{
    Graph t(g.size(), ve());
    for (int i = 0; i < g.size(); i++)
        for (int j = 0; j < g[i].size(); j++)
            t[j].pb(i);

    return t;
}

void dfs_kosaraju(int vertex)
{
    marc[vertex] = true;
    for (int i = 0; i < adjs.size(); i++)
        if (!marc[i])
            dfs(adjs[vertex][i].dst);

    q_kosaraju.insert(vertex);
}

Graph t = transpose(adjs);

void dfs_t()
{
    marc[vertex] = true;
    for (int i = 0; i < adjs.size(); i++)
        if (!marc[i])
            dfs(adjs[vertex][i].dst);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n, a, b, c;

    cin >> n;

    adjs = Graph(n, vector<Edge>());
    marc = vi(n, INF);

    while (cin >> a >> b >> c)
        adjs[a].pb(Edge(b, c));

    debug(adjs);
    debug(floyd());

    return 0;
}

//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
//python s.py < in.txt > out.txt
