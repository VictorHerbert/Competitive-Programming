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

//WARNING
#define FOR(i, n) for (int i = 0; i < n; i++)

pair<int, int> common(const string &s, const string &begin)
{
    if (s.size() < begin.size())
        return mp(0, 0);

    int pos = 0, idx = 0;
    FOR(i, begin.size())
    {
        if (s[i] != begin[i])
            break;
        else if (s[i] == '/')
        {
            idx = i + 1;
            pos += 3;
        }
    }
    if (idx == begin.size())
        pos = 0;

    return mp(idx, pos);
}

int main()
{
    //ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vs v(n);
    ll ccount = 0;
    for (auto &s : v)
    {
        cin >> s;
        ccount += s.size();
    }

    map<string, int> roots;

    for (string s : v)
    {
        int pos = 0, level = 3;
        FOR(j, s.size())
        {
            if (s[j] == '/')
            {
                roots[s.substr(0, j + 1)] = level;
                pos = j + 1;
                level += 3;
            }
        }
    }

    ll mn = 0;

    for (auto root : roots)
    {
        ll acum = 0;
        for (string s : v)
        {
            auto c = common(s, root.first);
            if (c.first)
                acum = acum - c.first + c.second;
            else
                acum += root.second;
        }

        mn = min(mn, acum);
    }

    cout << ccount + mn << "\n";

    return 0;
}
//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
