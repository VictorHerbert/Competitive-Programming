

int n,xa,xb;

GD_INIT("point.html");
//GD_LINE(0, 0, 0, 1, "bold");
//GD_LINE(0, 0, 1, 0, "bold");

GD_SEGMENT(1,1,2,3);

GD_RECT(0, 0, 2, 2);

cin >> n >> xa >> xb;

//GD_SEGMENT(xa, 0, xb, 0, "red");
vector<Point> points(n);
for(auto& p : points){
    cin >> p.x >> p.y;
    GD_POINT(p.x, p.y);
    GD_PAUSE();
}



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

Point p1, p2;
cin >> p1.x >> p1.y >> p2.x >> p2.y;
Line l1(p1, p2);
debug(l1);
debug(RAD_TO_DEG(l1.ang()));

cin >> p1.x >> p1.y >> p2.x >> p2.y;
Line l2(p1, p2);
debug(RAD_TO_DEG(l2.ang()));

debug(RAD_TO_DEG(angleBetween(l2, l1)));
