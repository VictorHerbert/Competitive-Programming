int lis(vi& v){
    vi seq = {v[0]};
    for(int i = 1; i < v.size(); i++){
        auto it = lower_bound(seq.begin(),seq.end(),v[i]);
        if(it == seq.end())
            seq.pb(v[i]);
        else
            *it = v[i];

    }
    return seq.size();
}

vector<bool> subsetSum(vector<int> &v){
    int acum = 0;
    for (auto i : v)
        acum += i;

    vector<bool> e(acum, false);
    e[0] = true;

    for (int i = 0; i < v.size(); i++){
        for (int j = e.size() - 1; j - v[i] > -1; j--){
            if (e[j - v[i]])
                e[j] = true;
        }
    }

    return e;
}

ll largestSubarray(vi &v){
    ll g_acum = 0, acum = 0;

    for (int i : v)
    {
        acum += i;
        if (acum < 0)
            acum = 0;
        g_acum = max(g_acum, acum);
    }

    return g_acum;
}