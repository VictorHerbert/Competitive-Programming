//#include <bits/stdc++.h>

#if __has_include("../Util/print.h")
#include "../Util/print.h"
#endif

using namespace std;

double EPS = 1e-9;
int INF = INT_MAX / 4;
unsigned long long MOD = 1e9 + 7;
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

int lis(vi& v){
    vi seq = {v[0]};
    for(int i = 1; i < v.size(); i++){
        auto it = lower_bound(seq.begin(),seq.end(),v[i]);
        if(it == seq.end())
            seq.pb(v[i]);
        else
            *it = v[i];

    }
    return seq.size();
}

int main(){    
    ios_base::sync_with_stdio(false), cin.tie(0);
    //cout << fixed << setprecision(10);

    vi v = { 50, 3, 10, 7, 40, 80};

    debug(lis(v));
    return 0;
}
//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
//python s.py < in.txt > out.txt