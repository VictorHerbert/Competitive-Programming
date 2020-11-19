#include <bits/stdc++.h>
#define DEBUG

#ifndef ONLINE_JUDGE
    #define DEBUG_MAT
    #if __has_include("../Util/debug.h")
        #include "../Util/debug.h"
    #endif
#else
    #define debug(x) {}
    #define debug2(x1, x2) {}
    #define debug3(x1, x2, x3) {}
    #define debug4(x1, x2, x3, x4) {}
#endif


using namespace std;

#define ld double
const ld EPS = 1e-9;
const int INF = INT_MAX / 4;
const unsigned long long MOD = 1e9 + 7;
inline bool D_EQ(double a, double b) { return abs(a - b) < EPS; }
const ld PI = 4 * atan(1);

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ull unsigned long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vb vector<bool>

#define mp make_pair
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define FIND(v, c) find(v.begin(), v.end(), c) != v.end()
#define FOR(i, a, b) for (auto i = a; i != b; i++)
#define REP(n) FOR(_, 0, n)
inline int inRange(int i, int a, int b){return a <= i && i < b;}
inline int inRange2D(int i, int j, int a, int b) { return inRange(i, 0, a) && inRange(j, 0, b); }
inline int toIdx(int i, int j, int n) { return i * n + j; }
inline ld clamp(ld v, ld a, ld b) { return max(a, min(v, b)); }
const vvi orto = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const vvi diag = {{1, 1}, {0, -1}, {1, 0}, {-1, 0}};
const vvi dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {0, -1}, {1, 0}, {-1, 0}};

#define Edge pair<int,int>
#define Graph vector<vector<Edge>>
#define weight first
#define dst second
#define make_edge(a,b) mp(b,a)


Graph adjs;
vi marc;

void dijikstra(int vertex){
    set<Edge> fila;
    fila.insert(make_edge(vertex,0));
    marc[vertex] = 0;

    int current, w;
    while(!fila.empty()){
        tie(w,current) = *fila.begin();
        fila.erase(*fila.begin());

        for(auto adj : adjs[current])
            if(marc[adj.dst] == INF){
                fila.insert(adj);
                marc[adj.dst] = marc[current]+adj.weight;
            }        
    }
}

int main(){
    int n,m,a,b,c;

    cin >> n >> m;
    adjs = Graph(2*n,vector<Edge>());
    REP(n){
        cin >> a >> b >> c;
        a--, b--;


        adjs[2 * a].pb(make_edge(2 * b + 1, c));
        adjs[2 * b].pb(make_edge(2 * a + 1, c));
        
        adjs[2 * a + 1].pb(make_edge(2 * b, c));
        adjs[2 * b + 1].pb(make_edge(2 * a, c));
    }

    marc = vi(2*n,INF);
    dijikstra(0);

    //debug(marc);

    if (marc[2 * (n - 1)] != INF)
        cout << marc[2 * (n - 1)] << "\n";
    else
        cout << "-1\n";



    return 0;
}
//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
