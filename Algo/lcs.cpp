#include <bits/stdc++.h>

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

string s1,s2;
vvi v_cls;


int lcs(int a, int b){
    if (v_cls[a][b] == -1){
        if((a && b) == 0){
            v_cls[a][b] = 0;
        }
        else{            
            int acum = 0;
            if (s1[a - 1] == s2[b - 1]){
                acum = lcs(a-1,b-1)+1;
                //debug3(a,b,acum); 
            }

            acum = max(acum,max(lcs(a,b-1),lcs(a-1,b)));
            v_cls[a][b] = acum;
        }
    }

    return v_cls[a][b];
}

int main()
{
    cout << "Hello World!\n";
    return 0;

    ios_base::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(2);
    
    int n,h,w,cas = 1;
    ll acum = 0;
    string s;

    cin >> n;
    while(n--){
        vs v;
        int x,y;
        s1.clear(),s2.clear();

        cin >> h >> w;        
        while(h--){
            cin >> s;
            v.pb(s);
        }
        
        cin >> w >> x >> y >> s;
        x--, y--;

        s1.pb(v[x][y]);
        for (char c : s){
            switch (c){
            case 'E':
                y++;
                break;
            case 'W':
                y--;
                break;
            case 'N':
                x--;
                break;
            case 'S':
                x++;
                break;
            }
            s1.pb(v[x][y]);
        }
        cin >> w >> x >> y >> s;
        x--, y--;

        s2.pb(v[x][y]);
        for (char c : s)
        {
            switch (c)
            {
            case 'E':
                y++;
                break;
            case 'W':
                y--;
                break;
            case 'N':
                x--;
                break;
            case 'S':
                x++;
                break;
            }
            s2.pb(v[x][y]);
        }

        //debug2(s1,s2);

        v_cls = vvi(s1.size() + 1, vi(s2.size() + 1, -1));
        int a = lcs(s1.size(), s2.size());
        //debug(a);
        cout << "Case " << cas << ": " << s1.size() - a << " " << s2.size() - a << "\n";
        cas++;
    }


    return 0;
}

//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
//python s.py < in.txt > out.txt