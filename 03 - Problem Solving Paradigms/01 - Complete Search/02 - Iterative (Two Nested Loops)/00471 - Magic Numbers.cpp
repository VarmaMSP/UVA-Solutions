#include <bits/stdc++.h>
#define MAX 9876543210

typedef long long i64;

bool check(i64 n) {
    bool mark[10] = { false };
    while (n) {
        if (mark[n % 10]) return false;
        mark[n % 10] = true;
        n /= 10;
    }
    return true;
}

int main() {
    int tt;
    i64 n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%lld", &n);
        for (i64 d = 1; d * n <= MAX; ++d) {
            if (check(d * n) && check(d)) {
                printf("%lld / %lld = %lld\n", d * n, d, n);
            }
        }
        if(tt) puts("");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
