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

#define Edge pair<int, int>
#define w first
#define dst second

//Parent
vi p, ranks;

void initUF(int n)
{
    p = vi(n + 1, -1);
    ranks = vi(n + 1, 1);
}

int findSet(int i)
{
    return (p[i] == -1) ? i : (p[i] = findSet(p[i]));
}

bool isSame(int a, int b)
{
    return findSet(a) == findSet(b);
}

void merge(int a, int b)
{
    a = findSet(a), b = findSet(b);

    if (ranks[a] > ranks[b])
        p[b] = a;
    else if (ranks[b] > ranks[a])
        p[a] = b;
    else
    {
        p[a] = b;
        ranks[b]++;
    }
}