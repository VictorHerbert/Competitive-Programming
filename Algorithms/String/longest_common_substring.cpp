int lcs(int a, int b){
    if (dp[a][b] == -1){
        if ((a && b) == 0)
            dp[a][b] = 0;
        else{
            int acum = 0, lim = min(a, b) + 1;
            while (s1[a - acum] == s2[b - acum] && lim--)
                acum++;

            acum = max(acum, max(lcs(a, b - 1), lcs(a - 1, b)));
            dp[a][b] = acum;
        }
    }

    return dp[a][b];
}