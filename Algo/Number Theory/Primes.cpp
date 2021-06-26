#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;
int INF = 1000000005;

#define ll long long;
#define ull unsigned long long ull;
#define pair <int, int> ii;
#define vector <int> vi;
#define vector <ii> vii;
#define vector <vector<int>> vvi;

#define mp make_pair
#define fi first
#define se second

#define pb push_back

//Complexity O(sqrt(n))
bool isPrime(long long n){
    long long upLimit = ceil(sqrt(n));
    for(long long i = 2; i < upLimit; i++)
        if(n%i == 0)
            return false;
    
    return true;
}

//For offline programming
vector<ll>& sieve(ll n){
    vector<int> primes;
    primes.pb(2);
    for(ll i = 3; i < n; i++){
        bool isPrime = true;
        for (int p : primes)
            if (i % p == 0){
                isPrime = false;
                break;
            }
        if(isPrime)
            primes.pb(i);
    }
    return primes;
}
