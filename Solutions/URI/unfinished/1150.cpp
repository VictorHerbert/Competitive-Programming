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

int main()
{

    int n,k;
    
    cin >> n;
    while(true){
        cin >> k;
        if(k > n)
            break;
    }
    
    int a=n,b=k,v = (a+b)/2;
    int d = v-a;
    
    int acum = 0;
    if(n < 0 ){
        acum = n;
        n = 0;
    }

    while (b-a > 1){
        cout << a << " " << b << "|" << d << "->" << (d * (d + 1) / 2 + n * d ) << "|";
        if ((d * (d + 1) / 2 + (n+1) * d + acum )> k){
            b = v;
            v = (a + b) / 2;
            d = v-n;
        }
        else{
            a = v;
            v = (a + b) / 2;
            d = v-n;
        }
        cout << a << " " << b << endl;
    }
    //v *(v + 1) > 2 * (k - n * n);
    cout << d+2 << "\n";

    return 0;
}