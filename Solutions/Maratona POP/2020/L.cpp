#include <bits/stdc++.h>
#define DEBUG


#if __has_include("../Util/debug.h")
    #include "../Util/debug.h"
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

int a1,b1,a2,b2;

void multiply(vvi mat1,
              vvi mat2,
              vvi& res){
    int i, j, k;
    for (i = 0; i < a1; i++) {
        for (j = 0; j < b2; j++) {
            res[i][j] = 0;
            for (k = 0; k < b1; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}
 

int main(){
    
    cin >> a1 >> b1;
    vvi m1(a1,vi(b1));
    for(auto& v : m1)
        for(int & i : v)
            cin >> i;
    cin >> a2 >> b2;
    vvi m2(a2,vi(b2));
    for(auto& v : m2)
        for(int & i : v)
            cin >> i;

    if(b1 == a2){
        vvi m3(a1,vi(b2));
        multiply(m1,m2,m3);
        for(auto& vv : m3){
            FOR(i,0,vv.size())
                cout << vv[i] << " \n"[i == vv.size()-1];
        }
    }
    else
        cout << "IMPOSSIVEL MULTIPLICAR\n";
    

   

    return 0;
}
//g++ -std=c++11 L.cpp -o s.exe & s.exe < ./io/in.txt > ./io/out.txt