#include <bits/stdc++.h>

typedef long long int i64;

int main() {
    int tt;
    i64 s;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%lld", &s);
        printf("%lld\n", (i64)floor(-0.5 + sqrt(0.25 + 2 * s)));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 8-Aug-2018
*/
