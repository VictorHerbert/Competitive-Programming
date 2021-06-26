// A C++ program to find orientation of three points 
#include <bits/stdc++.h> 

#if __has_include("../Util/debug.h")
    #include "../Util/debug.h"
#else
    #define debug(x){}
    #define debug2(x1, x2){}
    #define debug3(x1, x2, x3){}
    #define debug4(x1, x2, x3, x4){}
#endif

using namespace std; 
  
struct Point { 
    int x, y; 
}; 
  
int orientation(Point p1, Point p2, Point p3) { 
    int cross = (p2.y - p1.y) * (p3.x - p2.x) - 
              (p2.x - p1.x) * (p3.y - p2.y);     
  
    return (cross > 0);
} 
  

int main() { 
    vector<Point> pts(10);

    for(auto& p : pts)
        cin >> p.x >> p.y;

    set<bool> s;
    for(int i = 0; i < 10; i++)
        s.insert(orientation(
            pts[i],
            pts[(i+1)%10],
            pts[(i+2)%10]
        ));

    if(s.size() == 1)
        cout << "True\n";
    else
        cout << "False\n";


 
} 