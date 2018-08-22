#include <bits/stdc++.h>

int main() {
    int tt, n, m, p;
    bool S[1 << 10];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        memset(S, true, sizeof(S));
        while (m--) {
            scanf("%d", &p);
            S[p - 1] = false;
        }
        int res = 0;
        while (n) {
            for (int i = 0; i < (1 << n); i += 2) {
                if (S[i] ^ S[i + 1]) res += 1;
                S[i >> 1] = S[i] | S[i + 1];
            }
            n -= 1;
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 22-Aug-2018
*/
