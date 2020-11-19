

int lcs(int a, int b){
    if (dp[a][b] == -1)
    {
        if ((a && b) == 0)
            dp[a][b] = 0;
        else
        {
            int acum = 0, lim = min(a, b) + 1;
            while (s1[a - acum] == s2[b - acum] && lim--)
                acum++;

            acum = max(acum, max(lcs(a, b - 1), lcs(a - 1, b)));
            dp[a][b] = acum;
        }
    }

    return dp[a][b];
}

int largestPal(int l, int r){
    if (dp[l][r] != -1)
        return dp[l][r];

    if (l == r)
        return dp[l][r] = 1;
    else if (l + 1 == r)
        return dp[l][r] = 1 + (s[l] == s[r]);

    if (s[l] == s[r])
        return dp[l][r] = 2 + largestPal(l + 1, r - 1);
    else
        return dp[l][r] = max(largestPal(l, r - 1), largestPal(l + 1, r));
}
