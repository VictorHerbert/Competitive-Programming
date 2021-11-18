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

    Point pt = p[n-1];

    Circle c = welzl(p, n-1, r);

    if(c.isInside(pt))
        return c;
        
    r.pb(pt);
    return welzl(p, n-1, r);
}