#include <bits/stdc++.h>

#define DEBUG

#ifndef ONLINE_JUDGE
    #define DEBUG_MAT
    #if __has_include("../Util/debug.h")
        #include "../Util/debug.h"
    #endif
#else
    #define debug(x){}
    #define debug2(x1, x2){}
    #define debug3(x1, x2, x3){}
    #define debug4(x1, x2, x3, x4){}
#endif

using namespace std;

#define ld double
const ld EPS = 1e-9;
const int INF = INT_MAX / 4;
const unsigned long long MOD = 10;
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

inline ll msb_idx(ll n){
    for(ll i = 63; i >= 0; i--)
        if((n & (1ll << i)) != 0)
            return i;    
    return -1;
}

ll pascal[64][64];
inline ll cn(ll n, ll k){
    if(k < 0 or k > n)
        return 0;
    if(n == k or k == 0)
        return 1;

    if(pascal[n][k] == 0)
        pascal[n][k] = cn(n-1,k)+cn(n-1,k-1);

    return pascal[n][k];
}

ll f(ll n, ll k){
    ll msb = msb_idx(n);

    if(n == 0)
        return n == k;
    if(msb < k-1)
        return 0;
    if(k < 0 or k > n)
        return 0;
        
    return cn(msb,k) + f(n & ((1ll<<msb)-1), k-1);
}


inline pair<ll,ll> toBin(vll& v, ll n){
    ll acum = 0, sum = 0;
    for(ll i = v.size()-1; i >= 0; i--)
        if(n >= v[i]){
            n -= v[i];
            sum += v[i];
            acum |= (1ll << i);
        }
    return mp(acum,sum);
}


int main(){  

    ll n,k,a,b,sum,ab,bb;

    cin >> n >> k;
    vll v(n);
    for(ll& i : v)
        cin >> i;
    cin >> a >> b;

    sort(all(v));

    tie(ab,sum) = toBin(v,a);
    ab += sum < a;
    tie(bb,sum) = toBin(v,b);
    
    cout << f(bb,k)  - f(ab,k) + (__builtin_popcount(ab) == k) << "\n";
    

    
    return 0;
}
//g++ -std=c++11 H.cpp -o s.exe & s.exe < in.txt > out.txt