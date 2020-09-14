#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;
int INF = 1000000005;

#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vector<int>>

template <template <class, class> class Container, class T, class Alloc = std::allocator<T>>
std::ostream &operator<<(
    std::ostream &os,
    const Container<T, Alloc> &container)
{
    const char *sep[] = {"", ", "};
    int si = 0;
    os << "{ ";
    for (const T &elt : container)
    {
        os << sep[si] << elt;
        si = 1;
    }
    return os << " }";
}

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define sz size

vi v;

int merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vi L(v.begin()+l,v.begin()+m);
    vi R(v.begin()+m, v.begin()+r);
    i = 0,j = 0;

    cout << L << " " << R << endl;

    for (k = l; i < n1 && j < n2; k++)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }

    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }

    return 0;
}

int mergeSort(int a, int b){
    if(a >= b){
        cout << a << " " << b << " f" << endl;
        return 0;
    }
        
    int mid = (a+b)/2;

    cout << a << " " << mid << " " << b << "\n\n";

    int m1 = mergeSort(a,mid);
    int m2 = mergeSort(mid+1,b);

    return m1+m2+merge(a,mid,b);
}

int main()
{
    int n,k,l;

    
    cin >> n;
    while (n--)
    {
        v = vi();
        cin >> k;
        while (k--)
        {
            cin >> l;
            v.pb(l);
        }

        cout << v << endl;
        mergeSort(0,v.size()-1);
        cout << v << endl << endl;

        //cout << merge(0,v.size()) << "\n";
        
    }
    

}