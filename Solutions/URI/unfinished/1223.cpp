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

struct Point
{
    double x, y;
    Point(){};
    Point(double _x, double _y) : x(_x), y(_y) {}

    static double dist(const Point &a, const Point &b)
    {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
};

struct Line
{
    double a, b, c;
    Line(){};
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c){};
    
    Line(const Point& p1, const Point& p2){
        b = p2.y - p1.y;
        a = p1.x - p2.x;
        c = a * p1.x + b * p1.y;
    };

    static Line med(const Point &p1, const Point &p2)
    {
        double a = -2 * p1.x + 2 * p2.x;
        double b = -2 * p1.y + 2 * p2.y;
        double c = p1.x * p1.x + p1.y * p1.y - p2.x * p2.x - p2.y * p2.y;

        return Line(a, b, c);
    }
};

double dist(Point p, Line l){
    return abs(l.a * p.x + l.b * p.y - l.c)/ sqrt(l.a * l.a + l.b * l.b);
}

Point intersec(const Line &l1, const Line &l2)
{
    double d = (l1.a * l2.b - l2.a * l1.b);
    double x = -(l1.c * l2.b - l2.c * l1.b) / d;
    double y = -(l1.a * l2.c - l2.a * l1.c) / d;

    return Point(x, y);
}

struct Circle
{
    Point c;
    double r;

    Circle(const Point &_c, double _r) : c(_c), r(_r){};
    Circle(const Point &a, const Point &b)
    {

        c = {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
        r = Point::dist(a, b) / 2.0;
    };

    Circle(const Point &_a, const Point &_b, const Point &_c)
    {
        Line r1 = Line::med(_a, _b);
        Line r2 = Line::med(_a, _c);

        c = intersec(r1, r2);
        r = Point::dist(c, _a);
    };

    bool isInside(const Point &p)
    {
        return Point::dist(c, p) <= r;
    }
};

// g++ -std=c++11 s.cpp -o a.exe && a.exe < in.txt > out.txt
int main(){
    cout << fixed << setprecision(2);

    int n;
    double l, h, x1, y1, x2, y2;

    Line ln;
    Point po;

    //print(dist(Point(3,7),Line(-3,3,6)));
    Line k({0,0},{4,2});
    //print(k.a,k.b,k.c);

    //return 0;

    while (cin >> n >> l >> h)
    {
        double w[] = {0, l};
        double m = 1e8;

        cin >> y1 >> x2 >> y2;

        
        m = min(m, abs(x2 - w[1]));
        ln = Line(Point(w[0], y1), po);
        po = Point(x2, y2);

        for (int i = 1; i < n; i++)
        {
            cin >> y1 >> x2 >> y2;
            
            m = min(m, abs(x2 - w[(i + 1) % 2]));
            

            ln = Line(Point(w[i % 2], y1), {x2, y2});
            m = min(m, dist(po, ln));
            print(abs(x2 - w[(i + 1) % 2]), dist(po, ln));

            po = Point(x2, y2);

            

            //print(Point(w[i % 2], y1).x, Point(w[i % 2], y1).y, x2, y2);
            //print(po.x, po.y, ln.a, ln.b, ln.c, dist(po, ln));
        }

        print(m);
    }
    return 0;
}