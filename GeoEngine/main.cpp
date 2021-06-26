#include <bits/stdc++.h>
#include "primitives.hpp"
#include "matrix.hpp"
#define DEBUG_MAT
#include "../Util/debug.h"

using namespace std;
using namespace geo;

int main (){

    Matrix transformation = {{
        {2, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
    }};

    Matrix projection = {{
        {.1, 0, 0, 0},
        {0, .1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 1},
    }};

    Matrix point = {{
        {3,5},{4,9},{5,10},{1,1}
    }};
    
    Matrix pointTransf = transformation*point;

    debug(pointTransf.v);
    

}

//g++ -std=c++11 main.cpp -o main.exe & main.exe
