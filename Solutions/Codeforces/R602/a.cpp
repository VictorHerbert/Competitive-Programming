#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;
int INF = 1000000005;

#define ll long long
#define ull unsigned long long ull
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define vvi vector <vector<int>>

#define mp make_pair

#define pb push_back

int main(){
    ll t,n,a,b;
    cin >> t;
    while(t--){
        cin >> n;
        ll amax = -1, bmin = 999999999999;

        while(n--){
            cin >> a >> b;
            if (b < bmin){
                bmin = b;
            }
            if (a > amax){
                amax = a;
            }
        }

        cout << max(0ll,amax-bmin) << "\n";
    }


    return 0;
}