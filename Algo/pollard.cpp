inline f(ll x, ll c, ll m){
    return ((x*x)%m+c)%m;
}

ll p_rho(ll n){
    //auto f = [](ll x, ll c, ll m){return ((x*x)%m+c)%m;};
    REP(ITS){
        ll a = (rand()%(n-2))+2;
        ll b = a;
        ll c = (rand()%(n-1))+1;
        ll d;

        while(true){
            debug2(a,b);
            a = f(a,c, n);
            b = f(f(b,c, n),c, n);
            d = __gcd(abs(a-b),n);

            if(d != 1)
                return d;
            if(a == b)
                break;
        }
    }

    return -1;

}

int main(){
    srand(time(NULL));
    debug(p_rho(146803));
   
    return 0;
}

//g++ -std=c++11 s.cpp -o s.exe & s.exe < ./io/in.txt > ./io/out.txt
