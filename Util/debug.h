#ifndef DEBUG_PRINT_H
#define DEBUG_PRINT_H
#include <bits/stdc++.h>
using namespace std;

//----- General -------

template <template <class, class> class Container, class T, class Alloc = allocator<T>>
ostream &operator<<(
    ostream &os,
    const Container<T, Alloc> &container)
{
    const char *sep[] = {"", ", "};
    int si = 0;
    os << "[ ";
    for (const T &elt : container)
    {
        os << sep[si] << elt;
        si = 1;
    }
    return os << " ]";
}

//----- Matrix -------

#ifdef DEBUG_MAT
template <typename T>
ostream &operator<<(
    ostream &os,
    vector<vector<T>> &v)
{
    const char *sep[] = {"\t", "\n\t"};
    int si = 0;
    os << "[\n";
    for (vector<T> &vv : v)
    {
        os << sep[si] << vv;
        si = 1;
    }
    return os << " ]";
}
#endif

//----- Map -------

template <typename T1, typename T2>
ostream &operator<<(
    ostream &os,
    const map<T1, T2> &m
){
    const char *sep[] = {"", ", "};
    int si = 0;
    os << "{ ";
    for (const auto &elt : m)
    {
        os << sep[si] << elt.first << ": " << elt.second;
        si = 1;
    }
    return os << " }";
}

//----- Set -------

template <typename T1>
ostream &operator<<(
    ostream &os,
    const set<T1> &s
){
    const char *sep[] = {"", ", "};
    int si = 0;
    os << "{ ";
    for (const auto &elt : s)
    {
        os << sep[si] << elt;
        si = 1;
    }
    return os << " }";
}

//----- Pair -------

template <typename T1, typename T2>
ostream &operator << (
    ostream &os,
    const pair<T1, T2> p
){
    cout << '<' << p.first << "," << p.second << ">";
}

void print(){
    cout << endl;
}


void print_seg(vector<long long> t, int lvl = INT_MAX) {
    for(int i = 0; i < t.size()-1; i++) {
        cout << t[i+1] << " ";
        if(__builtin_popcount(i + 2) == 1){
            cout << endl;
            if(lvl-- == 0) break;
        }
    }
    cout << endl;
}
template <typename T>
void print(T t){
    cout << t << endl;
}

template <typename T, typename... Args>
void print(T t, Args... args){
    cout << t << " ";
    print(args...);
}

#define debug(x) print(#x, ":", x)
#define debug2(x1,x2) print(#x1, ":", x1, "\t|", #x2, ":", x2)
#define debug3(x1, x2, x3) print(#x1, ":", x1, "\t|", #x2, ":", x2, "\t|", #x3, ":", x3)
#define debug4(x1, x2, x3, x4) print(#x1, ":", x1, '|', #x2, ":", x2, '|', #x3, ":", x3, #x4, ":", x4)


#endif