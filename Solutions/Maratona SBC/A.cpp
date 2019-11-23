#include <bits/stdc++.h>

#define pb push_back
#define EPS 1e-8
#define eq(a,b) abs(a-b) < EPS

using namespace std;

class Point{
public:
    double x,y;

    Point(){}
    Point(double _x, double _y):
        x(_x),
        y(_y){}
};


double dist(Point& p1, Point& p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

class Circle{
public:
    Point c;
    double r;

    Circle(){}
    Circle(Point _c, double _r):
        c(_c),
        r(_r){}

};

bool intersec(Circle& c1, Circle& c2){
    return (dist(c1.c,c2.c) <= (c1.r + c2.r));
}

//  3
//0   2
//  1

vector<vector<int>> bloq = {{2,3},{2,3},{0,1},{0,1}};

double m, n;
vector<Circle> sensores;

bool collideWall(int w, Circle& c){
    switch(w){
    case 0:
        if((c.c.x <= c.r))
            return true;
        break;
    case 1:
        if((n-c.c.y <= c.r))
            return true;
        break;
    case 2:
        if((m-c.c.x <= c.r))
            return true;
        break;
    case 3:
        if((c.c.y <= c.r))
            return true;
        break;

    }

    return false;
}


vector<bool> marc;

bool bfs(int w){
    queue<int> fila;
    for(int i = 0; i < sensores.size(); i++){
        if(collideWall(w,sensores[i])){
            fila.push(i);
            marc[i] = true;
        }
    }
    int atual;
    while (!fila.empty()){
        atual = fila.front();
        fila.pop();
        for(int w2 : bloq[w]){
            if(collideWall(w2,sensores[atual]))
                return true;
        }
        for(int i = 0; i < sensores.size();i++){
            if(!marc[i]){
                if(intersec(sensores[atual],sensores[i])){
                    marc[i] = true;
                    fila.push(i);
                }
            }
        }
    }

    return false;

}

int main (){
    int k,a,b,c;


    cin >> m >> n >> k;
    marc = vector<bool> (k,false);

    while(k--){
        cin >> a >> b >> c;
        sensores.pb(Circle(Point(a,b),c));
    }

    if(bfs(0)){
        cout << "N\n";
    }
    else if(bfs(1)){
        cout << "N\n";
    }
    else if(bfs(2)){
        cout << "N\n";
    }
    else if(bfs(3)){
        cout << "N\n";
    }
    else{
        cout << "S\n";
    }

    return 0;
}