#include <bits/stdc++.h>

#if __has_include("../Util/print.h")
#include "../Util/print.h"
#endif

using namespace std;

const double EPS = 1e-9;
const int INF = INT_MAX / 4;
const unsigned long long MOD = 1e9 + 7;

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

#define all(x) x.begin(), x.end()

#define Edge pair<int, pair<int, bool>>
#define make_edge(a, w, d) mp(a, mp(w, d))
#define weight second.first
#define dst first
#define down second.second

vector<vector<Edge>> adjs;
vector<bool> marc;
ll acum = 0;

int bfs(int vertex)
{
    queue<int> q;
    q.push(vertex);
    marc[vertex] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        debug(current);

        for (Edge edge : adjs[current])
        {
            int dst = edge.dst;
            if (!marc[dst])
            {
                q.push(dst);
                debug(edge);
                acum += edge.weight;
                marc[dst] = true;
            }
        }
    }

    return acum;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n = 0, a = 0, b = 0, k = 0, g_acum = 0, pos = 0;
    string s;
    int prev, current;
    char c;
    map<string, set<string>> sdirs;

    map<string, int> table;
    table[""] = 0;

    cin >> n;
    while (n--)
    {
        cin >> s;
        s += '/';

        pos = 1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '/')
            {
                string parent = s.substr(0, pos - 1);
                string child = s.substr(0, i);

                if (table.count(child) == 0)
                    table[child] = table.size() - 1;

                if (sdirs.count(parent) == 0)
                {
                    set<string> st;
                    st.insert(child);
                    sdirs[parent] = st;
                }
                else
                    sdirs[parent].insert(child);

                pos = i + 1;
            }
        }
    }

    // String adj list to int adj list
    adjs = vector<vector<Edge>>(table.size(), vector<Edge>());

    for (auto it : sdirs)
    {
        vector<Edge> &v = adjs[table[it.first]];

        for (string ss : it.second)
        {
            v.pb(make_edge(
                table[ss],
                ss.size() - it.first.size() + (it.first == "" ? 0 : 1),
                true));
            adjs[table[ss]].pb(make_edge(
                table[it.first],
                ss.size() - it.first.size() + (it.first == "" ? 0 : 1),
                false));
        }
        //adj[table[it.first]] = v;
        //cout << it.second << "\n";
    }

    // - string map to int map

    debug(table);
    debug(sdirs);
    debug(adjs);
    acum = 0;
    marc = vector<bool>(table.size(), false);
    //bfs(0);
    print(acum);

    return 0;
}

//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
//python s.py < in.txt > out.txt