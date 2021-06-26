#ifndef GEO_PRIMITIVES_H
#define GEO_PRIMITIVES_H

#include <bits/stdc++.h>
#include "../Util/geo_debug.h"

using namespace std;

namespace geo{
    class Point{
    public:
        double x,y;
    
        Point() { x = 0, y = 0; }
        Point(double _x, double _y) : x(_x), y(_y) {}
    };

    class Segment{
    public:
        Point p1, p2;
    };

    inline void plot(Point p, string attr = ""){
        GD_POINT(p,attr);
    }

    inline void plot(Segment s, string attr = ""){
        GD_SEGMENT(s.p1,s.p2,attr);
    }

    inline void plot(vector<Point> v, string attr = ""){
        for(int i = 0; i < v.size(); i++){
            GD_SEGMENT(v[(i+1)%v.size()], v[i], attr);
            GD_POINT(v[i], attr);
        }
    }
}
#endif
