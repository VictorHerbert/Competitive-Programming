#include<bits/stdc++.h>
#include "../../Util/debug.h"
#include "point.cpp"

using namespace std;

int main (){
    Point a = {3,6}, b = {0,0}, c = {8,0};
    Point a_n = a.normalized();

    assert(D_EQ(a_n.x, 0.44721359549995793) && D_EQ(a_n.y, 0.89442719099991586));
    assert(D_EQ(a_n.norm(), 1));
    assert(D_EQ(dist(a,c), 7.810249675906654));

    assert(orientation(a,a_n,b) == COLINEAR);
    assert(orientation(a,b,c) == LEFT);
    assert(orientation(a,b,c) == CCW);
    assert(orientation(a,c,b) == RIGHT);
    assert(orientation(a,c,b) == CW);
    assert(orientation(a,a,b) == COLINEAR);


    print("All tests passed");
    return 0;
}

