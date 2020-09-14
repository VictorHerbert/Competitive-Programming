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

#define ANGLE_COUNT 1000

//#define PI 3.14159265358979323846
#define PI 1.57079633

int main()
{
    int r,h,v,g;
    double vy,t,vx,A,a;
    vector<double> vsin,vcos;
    vector<double> vsin,vcos;

    for (int i = 0; i < ANGLE_COUNT; i++){
        vsin.pb(sin((double)i * PI / ANGLE_COUNT));
        vcos.pb(cos((double)i * PI / ANGLE_COUNT));
    }


    while(cin >> r >> h >> v >> g){
        A = 0;
        for(int i = 0; i < ANGLE_COUNT; i++){

            vy = v * vsin[i];

            t = (vy + sqrt(vy * vy + 2 * g * h)) / g;

            vx = v * vcos[i];

            a = vx * t;
            cout <<a << endl;
            if(a < A){}
                //break; 
            else
                A = a;
        }
        //cout << A << endl;
        if ((A - r) > 0.01)
            cout << "Y\n";
        else
            cout << "N\n";
    }
  
    return 0;
}