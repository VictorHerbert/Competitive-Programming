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
    int m,n,k;

    while (cin >> m >> n){
        vector<bool> v(m+1,true);
        while (n--){
            cin >> k;
            v[k] = false;
        }
        bool isEmpty = true;
        for (int i = 1; i < v.size(); i++){
            if(v[i]){
                cout << i << " ";
                isEmpty = false;
            }
        }
        if(isEmpty)
            cout << "*\n";
        else
            cout << "\n";
        
        
        
    }
    return 0;
}