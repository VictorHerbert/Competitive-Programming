#include <bits/stdc++.h>
#define DEBUG

#if __has_include("../Util/debug.h")
#define DEBUG_MAT
#include "../Util/debug.h"
#else
#define debug(x){}
#define debug2(x1, x2){}
#define debug3(x1, x2, x3){}
#define debug4(x1, x2, x3, x4){}
#endif

using namespace std;

const long double EPS = 1e-6;
const int INF = INT_MAX/2;
const unsigned long long MOD = 1e9 + 7;
const unsigned long long ITS = 1e4;

typedef double ld;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ull unsigned long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vb vector<bool>

inline bool D_EQ(ld a, ld b){return abs(a - b) < EPS;}
#define mp make_pair
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define FIND(v, c) find(v.begin(), v.end(), c) != v.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REP(n) FOR(_, 0, n)
inline int inRange(int i, int a, int b){return a <= i && i <= b;}
inline int inRange2D(int i, int j, int a, int b) { return inRange(i, 0, a) && inRange(j, 0, b); }
inline int toidx(int i, int j, int n) { return i * n + j; }
inline ld clamp(ld v, ld a, ld b) { return max(a, min(v, b)); }
const vvi orto = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const vvi diag = {{1, 1}, {0, -1}, {1, 0}, {-1, 0}};
const vvi dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {0, -1}, {1, 0}, {-1, 0}};


int main(){

    return 0;
}



//g++ -std=c++11 s.cpp -o ./io/s.exe & io\s.exe < ./io/in.txt > ./io/out.txt