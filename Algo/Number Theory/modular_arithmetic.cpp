long long modPow (long long base, long long exp, long long m){
    if(exp == 1)
        return base%m;
    if(exp%2 == 0){
        long long aux = modPow(base,exp/2,m);
        return (aux*aux)%m;
    }
    else{
        long long aux = modPow(base,exp/2,m);
        return (aux*aux*base)%m;
    }
}
