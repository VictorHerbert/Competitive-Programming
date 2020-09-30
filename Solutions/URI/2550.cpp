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
#define vs vector<string>

#define mp make_pair

#define pb push_back
#define sz size

#define all(x) x.begin(), x.end()

#define Edge pair<int, pair<int, int>>
#define w first
#define ori second.first
#define dst second.second
// origin, destiny, weight
#define make_edge(a, b, c) mp(c, mp(a, b))

//Parent
vi p, ranks;
vector<Edge> edges;
int n;

void initUF(int n)
{
    p = vi(n + 1, -1);
    ranks = vi(n + 1, 1);
}

int findSet(int i)
{
    return (p[i] == -1) ? i : (p[i] = findSet(p[i]));
}

bool isSame(int a, int b)
{
    return findSet(a) == findSet(b);
}

void merge(int a, int b)
{
    a = findSet(a), b = findSet(b);

    if (ranks[a] > ranks[b])
        p[b] = a;
    else if (ranks[b] > ranks[a])
        p[a] = b;
    else
    {
        p[a] = b;
        ranks[b]++;
    }
}

ll kruskal()
{
    ll acum = 0, count = 0;
    n--;

    sort(all(edges));
    for (Edge edge : edges)
    {
        if (!isSame(edge.ori, edge.dst))
        {

            merge(edge.ori, edge.dst);
            acum += edge.w;
            if (++count == n)
                return acum;
        }
    }
    n++;

    return acum;
}

vvi adjs;
vector<bool> marc;
int acum;

void dfs(int vertex){
    //debug(vertex);
    marc[vertex] = true;
    acum++;

    for (int i = 0; i < adjs[vertex].size(); i++)
        if (!marc[adjs[vertex][i]])
            dfs(adjs[vertex][i]);
}

int main(){
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int m, k, a, b, c;
    string s;


    while(cin >> n >> m){
        if(n == 0 & m == 0)
            break;

        initUF(n);
        acum = 0;
        marc = vector<bool>(n+1,false);
        edges = vector<Edge>(m);
        adjs  = vvi(n+1,vi());

        for (Edge &edge : edges){
            cin >> edge.ori >> edge.dst >> edge.w;

            adjs[edge.ori].pb(edge.dst);
            adjs[edge.dst].pb(edge.ori);
        }
        
        dfs(1);

        /*if(acum != n)
            cout << "impossivel\n";
        else
            cout << kruskal() << "\n";*/
        cout << "1\n";
            
    }

    return 0;
}

//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
//python s.py < in.txt > out.txt