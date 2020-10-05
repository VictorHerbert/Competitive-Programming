#include <bits/stdc++.h>

/*#if __has_include("../Util/print.h")
#include "../Util/print.h"
#endif*/

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

int getInvCount(string s, int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (s[i] > s[j]) 
                inv_count++; 

    return inv_count;
}


bool csort(pair<int,string> p1,pair<int,string> p2){
    return  (p1.first < p2.first);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,w,n;

    cin >> t;
    int i = 0;

    while(t--){
        if(i++)
            cout << "\n";
        cin >> n >> w;
        vector<pair<int,string>> v(w);
        for(auto& is : v){
            cin >> is.second;
            is.first = getInvCount(is.second, is.second.size());
        }

        stable_sort(all(v));
        //debug(v);
        for(auto& is : v)
            cout << is.second <<  endl;
    }


    return 0;
}

//g++ -std=c++11 B.cpp -o s.exe & s.exe < in.txt > out.txt && python copy.py
//python s.py < in.txt > out.txt
