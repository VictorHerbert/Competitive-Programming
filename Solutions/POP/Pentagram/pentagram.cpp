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

const double PI = atan(1.0)*4;
const double PI_2 = PI*2;
const double DEG_to_RAD_CONST = PI/180;
#define DEG_TO_RAD(x) x *DEG_to_RAD_CONST

//----------------- Structs ------------------------------

struct Point{
    double x, y;

    Point() {x = 0, y = 0;}
    Point(double _x, double _y) : x(_x),y(_y) {}
};

struct PointPolar{
    double r, a;

    PointPolar() { r = 0, a = 0; }
    PointPolar(double _r, double _a) : r(_r), a(_a) {}
};

struct Circle{
    Point center;
    double r;

    Circle() {}
    Circle(Point _center, double _r) : center(_center), r(_r) {}
};

// ax+by+c=0
struct Line
{
    double a, b, c;

    Line() {}
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    Line(Point &p1, Point &p2)
    { // If b == 0 is vertical, b == 1 otherwise
        if (abs(p1.x - p2.x) < EPS)                                // Vertical
            a = 1.0, b = 0.0, c = -p1.x; // default values
        else{
            a = -(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0;
            c = -(a * p1.x) - p1.y;
        }
    }

    double angCoef(){
        return -a / b;
    }
    double offset(){
        return -c / b;
    }
};

//----------------- Points ------------------------------

PointPolar toPolar(Point p){
    return PointPolar(sqrt(p.x * p.x + p.y * p.y), atan(p.y / p.x));
}
Point toRect(PointPolar p){
    return Point(p.r*cos(p.a),p.r*sin(p.a));
}

Point rotateArround(Point& p, Point& o, double theta){
    Point r;
    r.x = cos(theta) * (p.x-o.x) - sin(theta) * (p.y-o.y) + o.x;
    r.y = sin(theta) * (p.x-o.x) + cos(theta) * (p.y-o.y) + o.y;
    return r; 
}

#define COLINEAR 0
#define COUNTERCLOCK 1
#define CLOCKWISE 2

//Counter clockwise
bool orientation(Point p1, Point p2, Point p3){

    int val = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);

    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

//----------------- Lines ------------------------------

bool areParallel(Line l1, Line l2){
    return (abs(l1.a - l2.a) < EPS) && (abs(l1.b - l2.b) < EPS);
}
bool areSame(Line l1, Line l2){
    return areParallel(l1, l2) && (abs(l1.c - l2.c) < EPS);
}

//----------------- Distances ------------------------------

double dist(Point &p1, Point &p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

///

bool inside(Circle &c, Point& p){
    return dist(c.center,p) < c.r;
}

//----------------- Intersections ------------------------------

bool intersec(Circle &c1, Circle &c2){
    return (dist(c1.center, c2.center) <= (c1.r + c2.r));
}

// a1x + b1y + c1 = 0 and a2x + b2y + c2 = 0.
Point intersectPoint(Line& l1, Line& l2){
    Point p;
    
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    
    if (abs(l1.b) > EPS) // If vertical
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    
    return p;
}

//----------------- Polygon ------------------------------

typedef vector<Point> Polygon;

double perimeter(Polygon& p){
    double result = 0.0;
    for (int i = 0; i < p.size() - 1; i++) // remember that P[0] = P[n-1]
        result += dist(p[i], p[i + 1]);

    return result;
}

double area(Polygon &p){
    double area = 0.0;
    int j = p.size() - 1;

    for (int i = 0; i < p.size(); i++){
        area += (p[j].x + p[i].x) * (p[j].y - p[i].y);
        j = i;
    }

    return abs(area / 2.0);
}

ostream &operator<<(ostream &os, const Point &p)
{
    os << "(x: " << p.x << ", y: " << p.y << ")";
    return os;
}
ostream &operator<<(ostream &os, const PointPolar &p)
{
    os << "(r: " << p.r << ", a: " << p.a << ")";
    return os;
}
ostream &operator<<(ostream &os, const Circle &c)
{
    os << "(center: " << c.center << ", r: " << c.r << ")";
    return os;
}

ostream &operator<<(ostream &os, const Line &l)
{
    os << l.a << "x + " << l.b << "y + " << l.c << " = 0";
    return os;
}

int main(){

    ios_base::sync_with_stdio(false), cin.tie(0);

    double r;
    while (cin >> r){
        vector<Point> radPts;
        for (int i = 0; i < 5; i++){
            radPts.pb(toRect(PointPolar(r,(double) i * PI_2 / 5)));
        }
        vector<Line> lines;
        for (int i = 0; i < 5; i++){
            lines.pb(Line(radPts[i], radPts[(i + 2) % 5]));
        }
        Polygon p;
        for (int i = 0; i < 5; i++){
            p.pb(intersectPoint(lines[i], lines[(i + 1) % 5]));
        }

        cout << fixed << setprecision(3) << area(p) << "\n";
        p.pb(p[0]);
        cout << fixed << setprecision(3) << area(p) << "\n\n";
    }

    return 0;
}