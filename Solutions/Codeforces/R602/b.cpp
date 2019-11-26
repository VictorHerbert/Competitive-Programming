#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;
int INF = 1000000005;

#define ll long long
#define ull unsigned long long ull
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vector<int>>

#define mp make_pair
#define sz size

#define pb push_back

int main(){
    int t,n,k,kmax,minMarc;
    bool isPossible;
    vector<int> v;

    cin >> t;
    while (t--){
        cin >> n;
        v.clear();
        v.reserve(100000);
        vector<bool> marc(100000, true);

        isPossible = true;
        kmax = 0;
        minMarc = 1;

        while (n--){
            cin >> k;
            if(isPossible){
                if(k > kmax){
                    kmax = k;
                    marc[k] = false;
                    v.pb(k);
                }
                else if (k == kmax){
                    if(v.sz() == kmax)
                        isPossible = false;
                    else{
                        for(int i = minMarc; i < k; i++){
                            if(marc[i]){
                                minMarc = i+1;
                                marc[i] = false;
                                v.pb(i);
                                break;
                            }
                        }
                    }
                        
                }
                else {
                    isPossible = false;
                }
            }
        }
        if(isPossible){
            for(int i = 0; i < v.sz()-1;i++)
                cout << v[i] << " ";
            cout << v[v.sz()-1] << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    



    return 0;
}