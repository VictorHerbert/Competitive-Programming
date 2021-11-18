#include <bits/stdc++.h>

using namespace std;

//----------------- Constants & Macros ------------------------------
typedef long double ld;

const ld EPS = 1e-6;
const ld PI = 3.14159265358979323846;
const ld DEG_to_RAD_CONST = PI/180;
const ld RAD_TO_DEG_CONST = 180/PI;
inline bool D_EQ(ld a, ld b) {return abs(a - b) < EPS;}
inline ld DEG_TO_RAD(ld x){return x * DEG_to_RAD_CONST;} 
inline ld RAD_TO_DEG(ld x){return x * RAD_TO_DEG_CONST;}

//----------------- Point ------------------------------

struct Point{
    ld x, y;

    Point() { x = 0, y = 0; }
    Point(ld _x, ld _y) : x(_x), y(_y) {}

    Point operator + (Point other) {return Point(x + other.x, y + other.y);}
    Point operator - (Point other) {return Point(x - other.x, y - other.y);}
    Point operator * (ld k) const{return Point(x * k, y * k);}

    ld norm(){return hypot(x, y);}
    Point normalized(){return *this * (1 / norm());}
};


struct PointPolar{
    ld r, a;

    PointPolar() { r = 0, a = 0; }
    PointPolar(ld _r, ld _a) : r(_r), a(_a) {}
};

//----------------- Conversions ------------------------------

PointPolar Polar(Point p){
    return PointPolar(hypot(p.x, p.y), atan2(p.y, p.x));
}

Point toRect(PointPolar p){
    return Point(p.r * cos(p.a), p.r * sin(p.a));
}

//----------------- Vector ------------------------------



ld inner(Point p1, Point p2){return p1.x*p2.x + p1.y*p2.y;}
ld cross(Point p1, Point p2){
    cout << "|";
    return p1.x*p2.y - p2.x*p1.y;
}
Point proj(Point u, Point v){return v * (inner(u, v) / inner(v, v));}

//----------------- Misc ------------------------------

ld dist(Point p1, Point p2){return hypot((p1.x - p2.x), (p1.y - p2.y));}

#define COLINEAR 0
#define CCW 1 // CCW
#define CW 2 // CW
#define LEFT CCW
#define RIGHT CW

//Counter clockwise
int orientation(Point p1, Point p2, Point p3){
    Point a = p2-p1;
    Point b = p3-p1;
    ld val = cross(a, b);
    
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
