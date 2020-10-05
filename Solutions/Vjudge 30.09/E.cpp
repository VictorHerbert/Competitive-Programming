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

#define mp make_pair

#define pb push_back
#define sz size

#define all(x) x.begin(), x.end()

//----------------- Constants & Macros ------------------------------

const double PI = atan(1.0) * 4;
const double PI_2 = PI * 2;
const double DEG_to_RAD_CONST = PI / 180;
const double RAD_TO_DEG_CONST = 180 / PI;
#define DEG_TO_RAD(x) x *DEG_to_RAD_CONST
#define RAD_TO_DEG(x) x *RAD_TO_DEG_CONST
#define hypot(x, y) sqrt(x *x + y * y)

//----------------- Point ------------------------------

struct Point
{
    double x, y;

    Point() { x = 0, y = 0; }
    Point(double _x, double _y) : x(_x), y(_y) {}

    Point operator+(Point other) const
    {
        return Point(x + other.x, y + other.y);
    }
    Point operator-(Point other) const
    {
        return Point(x - other.x, y - other.y);
    }
    Point operator*(double k) const
    {
        return Point(x * k, y * k);
    }
};
//----------------- Misc ------------------------------

double dist(Point p1, Point p2)
{
    return hypot((p1.x - p2.x), (p1.y - p2.y));
}

bool cmp(Point a, Point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(Point a, Point b, Point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(Point a, Point b, Point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void convex_hull(vector<Point> &a)
{
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (i == a.size() - 1 || cw(p1, a[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2))
        {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}


#define COLINEAR 0
#define LEFT 1
#define RIGHT 2
#define Vec Point
double cross(Vec p1, Vec p2){
    return p1.x * p2.y - p1.y * p2.x;
}

bool collinear(Point p, Point q, Point r){
    //debug(abs(cross(p - q, p - r)));
    return abs(cross(p-q, p-r)) < EPS;
}

ostream &operator<<(ostream &os, const Point &p)
{
    os << "(: " << p.x << ", y: " << p.y << ")";
    return os;
}
int main()
{
    Point p1(0,0);
    Point p2(-1, -1);
    Point p3(1, 1);

    ios_base::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(2);
    int n, t;
    string s;

    int cas = 0;

    cin >> t;
    while (t--)
    {
        getline(cin, s);
        cin.ignore();

        cin >> n;

        vector<Point> pts(n);
        for (auto &pt : pts)
        {
            cin >> pt.x >> pt.y;
        }

        convex_hull(pts);
        double mn = 1e9, acum = 0;
        bool col = false;

        debug(pts);
        for (int i = 1; i < pts.size(); i++)
        {
            Point p(0, 0);
            //debug2(i, collinear(p, pts[i], pts[i - 1]));            

            acum += dist(pts[i], pts[i - 1]);
            debug(mn);

            mn = min(
                min(mn,2*hypot(pts[i].x,pts[i].y)),
                hypot(pts[i].x,pts[i].y) + hypot(pts[i-1].x,pts[i-1].y) - dist(pts[i], pts[i - 1])
            );
        }

        acum += dist(pts[0], pts[pts.size() - 1]);
        mn = min(
            min(mn, 2 * hypot(pts[0].x, pts[0].y)),
            hypot(pts[0].x, pts[0].y) + hypot(pts[pts.size() - 1].x, pts[pts.size() - 1].y) - dist(pts[0], pts[pts.size() - 1]));

        debug2(acum, mn);

        acum +=mn;

        if (cas++)
            cout << "\n";

        cout << acum+2 << "\n";
    }

    return 0;
}

//g++ -std=c++11 ../Template/stdGeo.cpp -o s.exe & s.exe < in.txt > out.txt