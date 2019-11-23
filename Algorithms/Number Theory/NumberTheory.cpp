
//GCD of a vector
long long gcd(vector<long long>& v){
    long long partial = v[0];

    for(long long l : v){
        partial = gcd(partial,l);
        if(partial == 1)
            return 1;
    }

    return partial;
}

//Euclidian extended GCD (Greatest Common Divisor) algorithm

// There are _gcd native implementation

// x and y are useful for Diophantine equations
// ax + by = GCD(a,b)
int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 

    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1); 

    *x = y1 - (b/a) * x1; 
    *y = x1; 

    return gcd; 
} 

// LCD - Least Common Multiple
ll lcd(ll a, ll b){
    return a*(b/gcd(a,b));
}
   
