
struct Point{
    double x,y;
    Point(){};
    Point(double _x, double _y) : x(_x), y(_y) {}

    static double dist(const Point &a, const Point &b){
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
};

struct Line
{
    double a, b, c;
    Line();
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c){};

    static Line med(const Point &p1, const Point &p2)
    {
        double a = -2 * p1.x + 2 * p2.x;
        double b = -2 * p1.y + 2 * p2.y;
        double c = p1.x * p1.x + p1.y * p1.y - p2.x * p2.x - p2.y * p2.y;

        return Line(a, b, c);
    }
};

Point intersec(const Line &l1,const Line &l2)
{
    double d = (l1.a * l2.b - l2.a * l1.b);
    double x = -(l1.c * l2.b - l2.c * l1.b) / d;
    double y = -(l1.a * l2.c - l2.a * l1.c) / d;

    return Point(x, y);
}

struct Circle{
    Point c;
    double r;

    Circle(const Point& _c, double _r) : c(_c),r(_r) {};
    Circle(const Point &a, const Point &b)
    {
        
        c = {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
        r = Point::dist(a, b) / 2.0;
    };

    Circle(const Point &_a, const Point &_b, const Point &_c)
    {
        Line r1 = Line::med(_a,_b);
        Line r2 = Line::med(_a,_c);

        c = intersec(r1,r2);
        r = Point::dist(c,_a);
    };

    bool isInside(const Point &p){
        return Point::dist(c, p) <= r;
    }
};

bool isValid(Circle& c, vector<Point> pts){
    for(Point p : pts)
        if(!c.isInside(p))
            return false;

    return true;
}

Circle welzl(vector<Point> &p, int n, vector<Point> r)
{
    if((n == 0) || (r.size() == 3)){
        assert(r.size() <= 3);
        switch (r.size()){
        case 0:
            return {{0,0},0};
        case 1:
            return Circle(r[0],0);
        case 2:
            return Circle(r[0], r[1]);
        case 3:
            for (int i = 0; i < 3; i++){
                for (int j = i + 1; j < 3; j++){
                    Circle c (r[i], r[j]);
                    if (isValid(c, p))
                        return c;
                }
            }
            return Circle(r[0],r[1],r[2]);
        }
    }

    int idx = rand() % n;
    Point pt = p[idx];
    swap(p[idx], p[n - 1]);

    Circle c = welzl(p, n-1, r);

    if(c.isInside(pt))
        return c;
        
    r.pb(pt);
    return welzl(p, n-1, r);
}
