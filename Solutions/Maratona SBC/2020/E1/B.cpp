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


int main(){  
    int n,d,l,r,c;
    vector<vb> v (10,vb(10,false));

    cin >> n;
    REP(n){
        cin >> d >> l >> r >> c;
        r--,c--;
        if(d)
            FOR(i,0,l){
                if(inRange2D(r+i,c,10,10)){
                    if(v[r+i][c]){
                        cout << "N\n";
                        return 0;
                    }
                    v[r+i][c] = true;
                }
                else{
                    cout << "N\n";
                    return 0;
                }
            }
        else
            FOR(i,0,l){
                if(inRange2D(r,c+i,10,10)){
                    if(v[r][c+i]){
                        cout << "N\n";
                        return 0;
                    }
                    v[r][c+i] = true;
                }
                else{
                    cout << "N\n";
                    return 0;
                }
            }
    }

    cout << "Y\n";

    
    return 0;
}
//g++ -std=c++11 B.cpp -o s.exe & s.exe < in.txt > out.txt
