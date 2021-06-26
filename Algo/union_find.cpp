//Parent
vi p, ranks;

void initUF(int n){
    p = vi(n + 1, -1);
    ranks = vi(n + 1, 1);
}

int findSet(int i){
    return (p[i] == -1) ? i : (p[i] = findSet(p[i]));
}

bool isSame(int a, int b){
    return findSet(a) == findSet(b);
}

void merge(int a, int b){
    a = findSet(a), b = findSet(b);

    if (ranks[a] > ranks[b])
        p[b] = a;
    else if (ranks[b] > ranks[a])
        p[a] = b;
    else{
        p[a] = b;
        ranks[b]++;
    }
}