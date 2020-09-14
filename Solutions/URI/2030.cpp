#include <bits/stdc++.h>

#if __has_include("print.h")
#include "print.h"
#define debug(x) print(#x, ":", x)
#endif

using namespace std;

double EPS = 1e-9;
int INF = INT_MAX/4;
unsigned long long MOD = 1e9+7;
#define TAM 1e6

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ull unsigned long long
#define vll vector<ll>
#define vvll vector<vector<ll>>

//#define mp make_pair

#define pb push_back
#define sz size

#define window 10

class Vertex{
public:
    int node;
    int weight;
};

ostream &operator<<(ostream &os, const Vertex &v)
{
    os << "<n: " << v.node << ", w: " << v.weight << ">";
    return os;
}

Vertex mp(int a, int b){
    Vertex v;
    v.node = a;
    v.weight = b;
    return v;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //cout << setprecision(10) << fixed;

    int n=0,a=0,b=0,k=0,acum=0,g_acum = 0,pos=0;
    string s;
    int prev,current;
    char c;
    map < string, set<string> > sdirs;
    
    map < string, int > table;
    table[""] = 0;
    

    cin >> n;
    while(n--){
        cin >> s;
        s+='/';

        pos = 1;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '/'){
                string parent = s.substr(0,pos-1);
                string child = s.substr(0,i);

                if (table.count(child) == 0)
                    table[child] = table.size()-1;                    
                

                if (sdirs.count(parent) == 0){
                    set<string> st;
                    st.insert(child);
                    sdirs[parent] = st;
                }
                else
                    sdirs[parent].insert(child);                

                pos = i+1;
            }
        }
    }


    // String adj list to int adj list
    vector<vector<Vertex>> adj(table.size(), vector<Vertex>());
    for (auto it : sdirs){
        vector < Vertex > v;
        for(string ss : it.second)
            v.pb(mp(table[ss], ss.size() - it.first.size() 
                + (it.first == "" ? 0 : 1)
            ));
        adj[table[it.first]] = v;
        //cout << it.second << "\n";
    }

    // - string map to int map
    
    debug(table);
    debug(sdirs);
    debug(adj);

    return 0;
}


//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
//python s.py < in.txt > out.txt