#include <bits/stdc++.h>
using namespace std;

template <template <class, class> class Container, class T, class Alloc = std::allocator<T>>
std::ostream &operator<<(
    std::ostream &os,
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

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os,
                         const std::map<T1, T2> &m)
{
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

template <typename T1>
std::ostream &operator<<(std::ostream &os,
                         const std::set<T1> &m)
{
    const char *sep[] = {"", ", "};
    int si = 0;
    os << "{ ";
    for (const auto &elt : m)
    {
        os << sep[si] << elt;
        si = 1;
    }
    return os << " }";
}

template <typename T1, typename T2>
std::ostream &operator<<(
    std::ostream &os,
    const pair<T1, T2> p)
{
    cout << '<' << p.first << "," << p.second << ">";
}

void print(){
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
#define debug2(x1,x2) print(#x1, ":", x1, '|', #x2, ":", x2)
#define debug3(x1, x2, x3) print(#x1, ":", x1, '|', #x2, ":", x2, '|', #x3, ":", x3)