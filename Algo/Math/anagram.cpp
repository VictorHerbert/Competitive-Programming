
ll f[(int) 1e3 + 1];

ll fat(ll n){
    if(f[n] == 0)
        f[n] = (n*fat(n-1))%MOD;

    return f[n];
}

ll modPow(ll n, ll e){
    if(e == 0)
        return 1;
    if(e%2)
        return (n * modPow((n * n) % MOD, e / 2)) % MOD;
    else
        return modPow((n * n) % MOD, e / 2) % MOD;
}

inline ll inv(ll n){
    return modPow(n,MOD-2);
}


int main(){
    f[0] = 1;    

    string s;
    map<char, int> cs;

    cin >> s;

    for(char c : s)
        cs[c]++;
    
    ll acum = fat(s.size());        

    for(auto p : cs)
        acum = (acum*inv(fat(p.second)))%MOD;            

    cout << acum << "\n";
        
    return 0;
}