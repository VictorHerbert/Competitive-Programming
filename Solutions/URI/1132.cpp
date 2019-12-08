#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;
int INF = 1000000005;

#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define vvi vector <vector<int>>

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define sz size

int main(){
    vi v(2);
    cin >> v[0] >> v[1];
    //v[0] = 100;
    //v[1] = 200;

    sort(v.begin(),v.end());

    ll acum = (v[1]-v[0]+1)*(v[0]+v[1]);
    acum/=2;


    v[0] = v[0]-v[0]%13+13;
    v[0]/=13;
    v[1] = v[1] - v[1] % 13;
    v[1]/=13;

    ll k = (v[1] - v[0] + 1) * (v[0] + v[1]);
    k/=2;

    cout << acum-13*k << "\n";

    return 0;
}