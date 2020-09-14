#include <bits/stdc++.h>

#if __has_include("print.h")
#include "print.h"
#define debug(x) print(#x, ":", x)
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
const double DEG_to_RAD_CONST = PI/180;
#define DEG_TO_RAD(x) x *DEG_to_RAD_CONST

struct Point{
    double x, y;

    Point() {x = 0, y = 0;}
    Point(double _x, double _y) : x(_x),y(_y) {}
};

double dist(Point &p1, Point &p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

pair<double, double> toPolar(Point& p){
    return pair<double, double>(sqrt(p.x*p.x+p.y*p.y), atan(p.y / p.x));
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
bool orientation(Point p1, Point p2, Point p3)
{

    // See 10th slides from following link for derivation
    // of the formula
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);

    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

struct Circle{
    Point center;
    double r;

    Circle() {}
    Circle(Point _center, double _r) : center(_center), r(_r) {}
};

bool inside(Circle &c, Point& p){
    return dist(c.center,p) < c.r;
}
bool intersec(Circle &c1, Circle &c2){
    return (dist(c1.center, c2.center) <= (c1.r + c2.r));
}

// ax+by+c=0
struct Line{
    double a, b, c;

    Line(){}
    Line(double _a, double _b, double _c) : a(_a),b(_b),c(_c){}
    Line(Point& p1, Point& p2){ // If b == 0 is vertical, b == 1 otherwise
        if (abs(p1.x - p2.x) < EPS){// Vertical
            a = 1.0, b = 0.0, c = -p1.x; // default values
        }
        else{
            a = -(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0;
            c = -(a * p1.x) - p1.y;
        }
        
    }
};

bool areParallel(Line l1, Line l2){
    return (abs(l1.a - l2.a) < EPS) && (abs(l1.b - l2.b) < EPS);
}
bool areSame(Line l1, Line l2){
    return areParallel(l1, l2) && (abs(l1.c - l2.c) < EPS);
}
// a1x + b1y + c1 = 0 and a2x + b2y + c2 = 0.
Point intersectPoint(Line& l1, Line& l2)
{
    Point p;
    
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    
    if (abs(l1.b) > EPS) // If vertical
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    
    return p;
}

struct Triangle{
    double ab,ac,bc;
    Point a,b,c;

    Triangle(){}
    Triangle(double _ab, double _ac, double _bc) : ab(_ab), ac(_ac), bc(_bc){}
    Triangle(Point &_a, Point &_b, Point& _c){
        a = _a, b = _b, c = _c;
        ab = dist(a, b), ac = dist(a, c), bc = dist(b, c);
    }
};

bool exists(Triangle& t){
    return (t.ab + t.bc > t.ac) && (t.ab + t.ac > t.bc) && (t.bc + t.ac > t.ab);
}

double perimeter(Triangle& t){
    return t.ab+t.ac+t.bc;
}

//Heron's
double area(Triangle& t){
    double s = perimeter(t)/2;
    return sqrt(s*(s-t.ab)*(s-t.bc)*(s-t.ac));
}

double rInCircle(double ab, double bc, double ca){
    Triangle t;
    return area(t) / (0.5 * perimeter(t));
}
double rCircumCircle(Triangle& t){
    return t.ab * t.bc * t.ac / (4.0 * area(t));
}

struct Polygon{
    vector<Point> pts;

    Polygon(){}
    Polygon(vector<Point> _pts): pts(_pts) {}
};

double perimeter(Polygon& p){
    p.pts.pb(p.pts[0]);

    double result = 0.0;
    for (int i = 0; i < p.pts.size() - 1; i++) // remember that P[0] = P[n-1]
        result += dist(p.pts[i], p.pts[i + 1]);

    p.pts.pop_back();
    return result;
}

double area(Polygon &p){
    p.pts.pb(p.pts[0]);
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int) p.pts.size() - 1; i++){
        x1 = p.pts[i].x;
        x2 = p.pts[i + 1].x;
        y1 = p.pts[i].y;
        y2 = p.pts[i + 1].y;
        result += (x1 * y2 - x2 * y1);
    }
    p.pts.pop_back();
    return abs(result) / 2.0;
}

ostream &operator<<(ostream &os, const Point &p)
{
    os << "(x: " << p.x << ", y: " << p.y << ")";
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

int main()
{

    ios_base::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(2);
    
    double ang;
    cin >> ang;
    debug(DEG_TO_RAD(ang));
    cout << endl;

    Point p;
    cin >> p.x >> p.y;
    debug(p);
    debug(toPolar(p));
    cout << endl;

    Circle c;    
    cin >> c.center.x >> c.center.y >> c.r;
    debug(c);
    cout << endl;

    Point p1,p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Line l(p1,p2);
    debug(l);


    return 0;
}

//g++ -std=c++11 s.cpp -o s.exe & s.exe < in.txt > out.txt
//python s.py < in.txt > out.txt