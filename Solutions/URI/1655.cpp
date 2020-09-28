#include <bits/stdc++.h>

#if __has_include("../Util/print.h")
#include "../Util/print.h"
#endif

using namespace std;

const double EPS = 1e-9;
const int INF = INT_MAX / 4;
const unsigned long long MOD = 1e9 + 7;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ull unsigned long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vs vector<string>

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

#define Edge pair<double, int>
#define Graph vector<vector<Edge>>
//#define make_adjs(n) vvd(n + 1, vd())
#define w first
#define dst second
#define make_edge(a, b) mp(b, a)

Graph adjs;
vd dist;
vector<bool> marc;

void dijikstra(int vertex)
{
    set<Edge> q;
    q.insert(make_edge(vertex, 1));
    dist[vertex] = 1;

    while (!q.empty())
    {
        auto aux = q.end();
        int current = (--aux)->dst;
        debug(*aux);
        q.erase(aux);
        marc[current] = true;

        for (auto edge : adjs[current])
        {
            double dest = edge.dst;
            if (!marc[dest])
            {
                dist[dest] = dist[current] * edge.w;
                //debug2(dist[current],edge.w);

                q.insert(make_edge(dest, dist[dest]));
            }
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int n, m, k, a, b;
    double c;
    ll acum = 0, g_acum = 0;
    string s;

    while (cin >> n)
    {
        if (n == 0)
            break;
        cin >> m;

        adjs = Graph(n + 1, vector<Edge>());
        dist = vd(n + 1, 0);
        marc = vector<bool>(n + 1, false);

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            adjs[a].pb(make_edge(b, c / 100));
            adjs[b].pb(make_edge(a, c / 100));
        }

        debug(adjs);
        dijikstra(1);
        debug(marc);
        cout << marc[n] << "\n";
    }

    return 0;
}

//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
//python s.py < in.txt > out.txt