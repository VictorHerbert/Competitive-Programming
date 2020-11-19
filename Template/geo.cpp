#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-6;
const int INF = INT_MAX / 4;
const unsigned long long MOD = 1e9 + 7;


#define ld long double
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ull unsigned long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vb vector<bool>

inline bool D_EQ(ld a, ld b) { return abs(a - b) < EPS; }
#define mp make_pair
#define pb push_back
#define sz size
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define FIND(v, c) find(v.begin(), v.end(), c) != v.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REP(n) FOR(_, 0, n)
inline int inRange(int i, int a, int b){return a <= i && i < b;}
inline int inRange2D(int i, int j, int a, int b) { return inRange(i, 0, a) && inRange(j, 0, b); }
inline int toidx(int i, int j, int n) { return i * n + j; }
inline ld clamp(ld v, ld a, ld b) { return max(a, min(v, b)); }
const vvi orto = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const vvi diag = {{1, 1}, {0, -1}, {1, 0}, {-1, 0}};
const vvi dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {0, -1}, {1, 0}, {-1, 0}};

//----------------- Constants & Macros ------------------------------

const ld PI = atan(1.0)*4;
const ld PI_2 = PI*2;
const ld DEG_to_RAD_CONST = PI/180;
const ld RAD_TO_DEG_CONST = 180/PI;
#define DEG_TO_RAD(x) x * DEG_to_RAD_CONST
#define RAD_TO_DEG(x) x * RAD_TO_DEG_CONST
#define hypot(x, y) sqrt(x *x + y * y)

//----------------- Point ------------------------------

struct Point{
    ld x, y;

    Point() { x = 0, y = 0; }
    Point(ld _x, ld _y) : x(_x), y(_y) {}

    Point operator + (Point other) const{
        return Point(x + other.x, y + other.y);
    }
    Point operator - (Point other) const{
        return Point(x - other.x, y - other.y);
    }
    Point operator*(ld k) const{
        return Point(x * k, y * k);
    }

    ld norm(){
        return hypot(x, y);
    }

    Point normalized(){
        return *this * (1 / norm());
    }
};

typedef vector<Point> Points;

struct PointPolar{
    ld r, a;

    PointPolar() { r = 0, a = 0; }
    PointPolar(ld _r, ld _a) : r(_r), a(_a) {}
};

#define Vec Point
//----------------- Conversions ------------------------------

PointPolar Polar(Point p){
    return PointPolar(hypot(p.x, p.y), atan2(p.y, p.x));
}

Point toRect(PointPolar p){
    return Point(p.r * cos(p.a), p.r * sin(p.a));
}

//----------------- Vector ------------------------------

ld inner(Vec p1, Vec p2){
    return p1.x*p2.x + p1.y*p2.y;
}
ld cross(Vec p1, Vec p2){
    return p1.x*p2.y + p2.x*p1.x;
}
Point proj(Vec u, Vec v){
    return v * (inner(u, v) / inner(v, v));
}

//----------------- Misc ------------------------------

ld dist(Point p1, Point p2){
    return hypot((p1.x - p2.x), (p1.y - p2.y));
}

#define COLINEAR 0
#define LEFT 1
#define RIGHT 2

//Counter clockwise
bool orientation(Point p1, Point p2, Point p3){
    int val = cross(p3 - p2, p2 - p1);
    
    if (abs(val) < EPS) return COLINEAR;
    return (val > 0) ? LEFT : RIGHT; // clock or counterclock wise
}

Point rotateArround(Point &p, Point &o, ld theta){
    Point r;
    r.x = cos(theta) * (p.x - o.x) - sin(theta) * (p.y - o.y) + o.x;
    r.y = sin(theta) * (p.x - o.x) + cos(theta) * (p.y - o.y) + o.y;
    return r;
}


ld angle(Point a, Point o, Point b){
    return acos(inner(a - o, b - o) / (dist(o, a) * dist(o, b)));
}


//----------------- Lines ------------------------------

// ax+by+c=0
struct Line{
    ld a, b, c;
    Point p1,p2;
    Vec v;

    Line() {}
    Line(ld _a, ld _b, ld _c) : a(_a), b(_b), c(_c) {}
    Line(Point _p1, Point _p2){ 
        p1 = _p1, p2 = _p2;              // If b == 0 is vertical, b == 1 otherwise
        if (abs(p1.x - p2.x) < EPS)      // Vertical
            a = 1.0, b = 0.0, c = -p1.x; // default values
        else
        {
            a = -(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.0;
            c = -(a * p1.x) - p1.y;
        }
        v = p1-p2;
    }

    ld angCoef(){
        return -a / b;
    }
    ld ang(){
        return atan(this->angCoef());
    }
    ld offset(){
        return -c / b;
    }
};


ld angle(Line l1, Line l2){
    return acos(inner(l1.v, l2.v) / (l1.v.norm()*l2.v.norm()));
}

bool areParallel(Line l1, Line l2){
    return (abs(l1.a - l2.a) < EPS) && (abs(l1.b - l2.b) < EPS);
}

bool areSame(Line l1, Line l2){
    return areParallel(l1, l2) && (abs(l1.c - l2.c) < EPS);
}

// a1x + b1y + c1 = 0 and a2x + b2y + c2 = 0.
Point intersectPoint(Line &l1, Line &l2){
    Point p;

    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    if (abs(l1.b) > EPS) // If vertical
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);

    return p;
}

Point projPointToLine(Point u, Line l){
    Point a, b;
    if (abs(l.b - 1.0) < EPS){
        a = Point(-l.c / l.a, 0.0);
        b = Point(-l.c / l.a, 1.0);
    }
    else{
        a = Point(0, -l.c / l.b);
        b = Point(1, -(l.c + 1.0) / l.b);
    }
    return a + proj(u - a, b - a);
}

//----------------- Segment ------------------------------

/*struct Segment : Line{
    Segment(Point a, Point b)  : Line(a,b){}
};


Point closestToSegment(Segment s, Point p, ){
    ld u = inner(p - s.p1, s.p2 - s.p1) / inner(s.p2 - s.p1, s.p2 - s.p1);

    if (u < 0.0)
        return s.p1;
    if (u > 1.0)
        return s.p2;
    return s.p1 + ((s.p2 - s.p1) * u);
}


bool inside(Segment s, Point p){
    return abs(inner(s.p1-p,s.p2-p) - 1) < EPS;
}

bool insideSeg(Segment s, point r){
    return collinear(s.p1, s.p2, r) && inner(s.p1 - s.p2, r - s.p2) <= 0;
}

bool intersectsSegLine(Segment s, Line l){
    return insideSeg(s, intersec(s, l));
}
bool intersectsSegSeg(Segment s, Segment l){
    Point p = intersec(s, l);
    return insideSeg(s, p) & intersec(l, p);
}

//----------------- Circles ------------------------------

struct Circle
{
    Point center;
    ld r;

    Circle() {}
    Circle(Point _center, ld _r) : center(_center), r(_r) {}
};

bool inside(Circle &c, Point &p){
    return dist(c.center, p) < c.r;
}

bool intersec(Circle &c1, Circle &c2){
    return (dist(c1.center, c2.center) <= (c1.r + c2.r));
}*/

//----------------- Triangles ------------------------------

struct Triangle
{
    ld ab, ac, bc;
    Point a, b, c;

    Triangle() {}
    Triangle(ld _ab, ld _ac, ld _bc) : ab(_ab), ac(_ac), bc(_bc) {}
    Triangle(Point &_a, Point &_b, Point &_c)
    {
        a = _a, b = _b, c = _c;
        ab = dist(a, b), ac = dist(a, c), bc = dist(b, c);
    }
};

bool exists(Triangle& t){
    return (t.ab + t.bc > t.ac) && (t.ab + t.ac > t.bc) && (t.bc + t.ac > t.ab);
}

ld perimeter(Triangle& t){
    return t.ab+t.ac+t.bc;
}

//Cossine law c^2 = a^2 + b^2 - 2ab cos C
Triangle byAngle(ld a, ld b, ld C){
    return Triangle(
        a,b,
        sqrt(a*a+b*b-2*a*b*cos(C))
    );
}

//Heron's
ld area(Triangle t){
    ld s = perimeter(t) / 2;
    return sqrt(s * (s - t.ab) * (s - t.bc) * (s - t.ac));
}

ld rInCircle(ld ab, ld bc, ld ca){
    Triangle t;
    return area(t) / (0.5 * perimeter(t));
}
ld rCircumCircle(Triangle &t){
    return t.ab * t.bc * t.ac / (4.0 * area(t));
}

bool inside(Triangle t, Point p){
    return 
        D_EQ( area(t),
            area(Triangle(t.a, t.b, p))+
            area(Triangle(t.a, p, t.c))+
            area(Triangle(p, t.b, t.c))
        );
}

/*
//----------------- Polygon ------------------------------

typedef vector<Point> Polygon;

ld perimeter(Polygon& p){
    ld result = 0.0;
    for (int i = 0; i < p.size() - 1; i++) // remember that P[0] = P[n-1]
        result += dist(p[i], p[i + 1]);

    return result;
}

ld area(Polygon &p){
    ld area = 0.0;
    int j = p.size() - 1;

    for (int i = 0; i < p.size(); i++){
        area += (p[j].x + p[i].x) * (p[j].y - p[i].y);
        j = i;
    }

    return abs(area / 2.0);
}*/

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

/*bool intersects(float cx, float cy, float radius, float left, float top, float right, float bottom)
{
    float closestX = (cx < left ? left : (cx > right ? right : cx));
    float closestY = (cy < bottom ? bottom : (cy > top ? top : cy));
    float dx = closestX - cx;
    float dy = closestY - cy;
    //debug2(closestX, closestY);

    return (dx * dx + dy * dy) <= radius * radius;
}*/
/*ostream &operator<<(ostream &os, const Circle &c)
{
    os << "(center: " << c.center << ", r: " << c.r << ")";
    return os;
}

ostream &operator<<(ostream &os, const Line &l)
{
    os << l.a << "x + " << l.b << "y + " << l.c << " = 0";
    return os;
}*/

//works for int coordinates
bool polarComp(Point a, Point b)
{
    if (b.y * a.y > 0)
        return cross(a, b) > 0;
    else if (b.y == 0 && b.x > 0)
        return false;
    else if (a.y == 0 && a.x > 0)
        return true;
    else
        return b.y < a.y;
}

inline bool polComp(Point a, Point b)
{
    return a.y * b.x >= b.y * a.x;
}

#ifdef DEBUG
    #if __has_include("../Util/geo_debug.h")

inline void plot(Point p){
    GD_POINT(p.x, p.y);
}
inline void plot(Line l){
    GD_LINE(
        l.p1.x, l.p1.y,
        l.p2.x, l.p2.y);
}
inline void plotSeg(Line l){
    GD_SEGMENT(
        l.p1.x, l.p1.y,
        l.p2.x, l.p2.y);
}

    #endif
#endif

bool insideSeg(Line l, Point r){
    return ((min(l.p1.x, l.p2.x) <= r.x) and (min(l.p1.y, l.p2.y) <= r.y) and (max(l.p1.x, l.p2.x) >= r.x) and (max(l.p1.y, l.p2.y) >= r.y))
        and  D_EQ(r.y, (-l.c - l.a * r.x) / l.b);
}

bool intersectsSegSeg(Line s, Line l){
    Point p = intersectPoint(s, l);
    return insideSeg(s, p) and insideSeg(l, p);
}

int main(){
    int n;
    Point p1,p2;
    Line l,l1,l2,l3,l4;
    ld x1,x2,y1,y2;
    cin >> n;

    REP(n){
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        cin >> x1 >> y1 >> x2 >> y2;

        if (
            (min(x1, x2) <= min(p1.x, p2.x)) and
            (max(x1, x2) >= max(p1.x, p2.x)) and
            (min(y1, y2) <= min(p1.x, p1.x)) and
            (min(y1, y2) >= min(p1.y, p2.y))
        )
            cout << "T\n";
        else{

            l = Line(p1, p2);

            
            l1 = Line(Point(x1, y1), Point(x1, y2));
            l2 = Line(Point(x1, y1), Point(x2, y1));
            l3 = Line(Point(x2, y2), Point(x1, y2));
            l4 = Line(Point(x2, y2), Point(x2, y1));

            if(
                intersectsSegSeg(l, l1) or
                intersectsSegSeg(l, l2) or
                intersectsSegSeg(l, l3) or
                intersectsSegSeg(l, l4)
            )
                cout << "T\n";
            else
                cout << "F\n";
        }

    }

    return 0;
}

//g++ -std=c++11 ../Template/stdGeo.cpp -o s.exe & s.exe < in.txt > out.txt

