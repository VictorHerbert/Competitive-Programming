#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;
int INF = 1000000005;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vector<int>>

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define sz size

int main(){
    int n,k,a;
    cin >> n >> k;

    int maxRow = 0;
    int currentRow = 1;
    vi v;
    while (n--){
        cin >> a;
        v.pb(a);
        if (*(v.end() - 1) - *(v.end() - 2) > k){
            maxRow = max(maxRow, currentRow);
            currentRow = 1;
        }
        else
            currentRow++;
    }
    maxRow = max(maxRow, currentRow);
    cout << maxRow << "\n";
    

    return 0;
}