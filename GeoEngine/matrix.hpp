#ifndef MATRIX_H
#define MATRIX_H

#include <bits/stdc++.h>
#include "../Util/debug.h"
#include "primitives.hpp"

using namespace std;

class Matrix{
public:
    vector<vector<double>> v;
    int m,n;

    Matrix(){}
    Matrix(int _m, int _n) :
        v(vector<vector<double>>(_m,vector<double>(_n))),
        m(_m),
        n(_n) {}
    Matrix(vector<vector<double>> _v) : 
        v(_v),
        m(_v.size()),
        n(_v[0].size()) {}

    /*Matrix(geo::Point p) : 
        v({{p.x},{p.y},{1.0}}),
        m(3),
        n(1){}
    
    geo::Point toPoint(){
        return {v[0][0], v[1][0]};
    }

    Matrix(vector<geo::Point> pts)
        : Matrix(3, pts.size())
    {
        for(int i = 0; i < pts.size(); i++){
            v[0][i] = pts[i].x;
            v[1][i] = pts[i].y;
            v[2][i] = 1;
        }
    }

    vector<geo::Point> toPoints(){
        vector<geo::Point> pts(n);

        for(int i = 0; i < n; i++)
            pts[i] = {v[0][i], v[1][i]};
        
        return pts;
    }*/

    Matrix operator*( Matrix const & b){
        if(n != b.m)
            throw length_error("Incompatible sizes\n");

        Matrix c(m, b.n);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < b.n; j++)
                for (int k = c.v[i][j] = 0; k < n; k++)
                    c.v[i][j] += v[i][k] * b.v[k][j];                
        return c;
    }
};

/*class Mat_2D : public Matrix {
public:
    Mat_2D (){}
    Mat_2D (geo::Point p) : Matrix({{p.x},{p.y},{1.0}}) {}
};*/

#endif

/*

| a 0 0 || x |
| 0 b 0 || y |
| 0 0 1 || 1 |


m = 4, n = 3
| a 0 0 || x |   | ax  |
| 0 b 0 || y |   | by  |
| 0 0 1 || 1 | = | 1   |
| 1 0 1 |        | x+1 |

*/