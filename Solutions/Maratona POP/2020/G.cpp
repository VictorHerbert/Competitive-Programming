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

vector<char> v;
string p = "tqer";

ll cnt = 0;
bool isValid(){
    FOR(i,0,v.size()-1){
        if((v[i] == 't') and (v[i+1] == 'e'))
            return false;
        if((v[i] != 'q') and (v[i+1] == 'r'))
            return false;
    }
    if(v[0] == 'r')
        return false;

    ll acum = 0;
    FOR(i,0,v.size())
        acum += (v[i] == 'e');
        
    return acum <= 1;
}

void rec(int pos){
    for(char c : p){
        v[pos] = c;
        if(pos < v.size()-1)
            rec(pos+1);
        else{
            //debug(isValid());
            cnt += isValid();
        }
    }
}

/*
i : 3 	| cnt : 22
i : 4 	| cnt : 59
i : 5 	| cnt : 157
i : 6 	| cnt : 414
i : 7 	| cnt : 1084
i : 8 	| cnt : 2821
i : 9 	| cnt : 7303
i : 10 	| cnt : 18820
i : 11 	| cnt : 48306
i : 12 	| cnt : 123551
i : 13 	| cnt : 315009
i : 14 	| cnt : 800890
*/

vi lut = {0,3,8,22,59,157,414,1084,2821,7303,18820,48306,123551,315009,800890,2031032};


int main(){
    /*int i = 15;
        v = vector<char>(i);
        cnt = 0;
        rec(0);
        debug2(i,cnt);*/

    ll x;
    cin >> x;

    cout << lut[x] << "\n";
    

    



    return 0;
}
//g++ -std=c++11 G.cpp -o s.exe & s.exe < ./io/in.txt > ./io/out.txt