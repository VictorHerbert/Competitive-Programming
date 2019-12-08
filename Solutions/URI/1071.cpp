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
    vi v(2);
    cin >> v[0] >> v[1];
    v[0] = abs(v[0]);
    v[1] = abs(v[1]);

    sort(v.begin(), v.end());

    v[0]++;
    v[0] = ((v[0] % 2 == 1) ? v[0] : v[0] + 1);
    
    v[1]--;
    v[1] = ((v[1] % 2 == 1) ? v[1] : v[1] - 1);

    if(v[0] > v[1]){
        cout << "0\n";
        return 0;
    }
    if (v[0] == v[1]){
        cout << v[0] << "\n";
        return 0;
    }
    else{
        v[0]--;
        v[0] /= 2;
        v[0] *= v[0];

        v[1]--;
        v[1] /= 2;
        v[1] *= v[1];

        cout << v[1] - v[0]<< "\n";


        return 0;
    }    
}

