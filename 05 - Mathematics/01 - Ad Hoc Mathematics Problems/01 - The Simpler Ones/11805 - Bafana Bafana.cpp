#include <bits/stdc++.h>

int main() {
    int tt, n, k, p, c = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d %d", &n, &k, &p);
        int res = (k + p) % n;
        if (res == 0) printf("Case %d: %d\n", c++, n);
        if (res != 0) printf("Case %d: %d\n", c++, res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 8-Aug-2018
*/
