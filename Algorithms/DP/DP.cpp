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
