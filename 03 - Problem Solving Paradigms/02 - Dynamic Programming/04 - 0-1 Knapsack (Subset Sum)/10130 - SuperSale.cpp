#include <bits/stdc++.h>

using namespace std;

int n, p[1010], w[1010];
int dp[1000][30000];

void solve(int S) {
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int s = 0; s <= S; ++s)
        dp[0][s] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int s = 1; s <= S; ++s) {
            if (w[i] > s)
                dp[i][s] = dp[i - 1][s];
            else
                dp[i][s] = max(dp[i - 1][s], p[i] + dp[i - 1][s - w[i]]);
        }
    }
}

int main() {
    int tt, m, S;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", p + i, w + i);
        }

        scanf("%d", &m);
        S = 0;
        vector< int > maxWeight(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &maxWeight[i]);
            S = max(S, maxWeight[i]);
        }
        solve(S);

        int res = 0;
        for (auto weight: maxWeight) {
            res += dp[n][weight];
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 16-Dec-2016
*/
