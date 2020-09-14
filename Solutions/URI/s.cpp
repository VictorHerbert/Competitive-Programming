#include <bits/stdc++.h>

using namespace std;


template <template <class, class> class Container, class T, class Alloc = std::allocator<T>>
std::ostream &operator<<(
    std::ostream &os,
    const Container<T, Alloc> &container)
{
    const char *sep[] = {"", ", "};
    int si = 0;
    os << "{ ";
    for (const T &elt : container)
    {
        os << sep[si] << elt;
        si = 1;
    }
    return os << " }";
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os,
                         const std::map<T1, T2> &m)
{
    const char *sep[] = {"", ", "};
    int si = 0;
    os << "{ ";
    for (const auto &elt : m)
    {
        os << sep[si] << elt.first << ": " << elt.second;
        si = 1;
    }
    return os << " }";
}

template <typename T1>
std::ostream &operator<<(std::ostream &os,
                         const std::set<T1> &m)
{
    const char *sep[] = {"", ", "};
    int si = 0;
    os << "{ ";
    for (const auto &elt : m)
    {
        os << sep[si] << elt;
        si = 1;
    }
    return os << " }";
}

template <typename T1, typename T2>
std::ostream &operator<<(
    std::ostream &os,
    const pair<T1, T2> p)
{
    cout << '<' << p.first << "," << p.second << ">";
}

template <typename T>
void print(T t)
{
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void print(T t, Args... args) // recursive variadic function
{
    cout << t << " ";

    print(args...);
}

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

//g++ -std=c++11 s.cpp -o a.exe && a.exe < in.txt > out.txt

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int m,n;
    vector<string> v;
    string s;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        v.pb(s);
    }
    queue<pair<int,int> > pts;
    pair<int,int> pt;
    
    pts.push(mp(0,v[0].find('o')));

    n--;
    while (!pts.empty())
    {
        pt = pts.front();
        if(pt.second > 0){
            while (v[pt.first][--pt.second] != 'o')
            {                
                v[pt.first][pt.second] = 'o';
                if (pt.second <= 0 or v[pt.first + 1][pt.second] != '#')
                    break;           
                
            }
            if (v[pt.first][pt.second] != '#')
                while (pt.first < n)
                {
                    if (v[++pt.first][pt.second] == '#')
                    {
                        pt.first--;
                        pts.push(pt);
                        break;
                    }
                    else
                        v[pt.first][pt.second] = 'o';
                }
        }
        
        if (pt.second < m-1)
        {
            pt = pts.front();
            while (v[pt.first][++pt.second] != 'o')
            {
                v[pt.first][pt.second] = 'o';
                if (pt.second >= m or v[pt.first + 1][pt.second] != '#' or v[pt.first][pt.second] != 'o')
                    break;
            }
            if (v[pt.first][pt.second] != '#')
                while (pt.first < n)
                {
                    if (v[++pt.first][pt.second] == '#')
                    {
                        pt.first--;
                        pts.push(pt);
                        break;
                    }
                    else
                        v[pt.first][pt.second] = 'o';
            }
        }
            
            //v[pt.first][pt.second]
            pts.pop();
    }
    for(string vv : v)
        cout << vv << "\n";
    


    return 0;
}
