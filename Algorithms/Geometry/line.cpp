
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