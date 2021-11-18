//TODO
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
