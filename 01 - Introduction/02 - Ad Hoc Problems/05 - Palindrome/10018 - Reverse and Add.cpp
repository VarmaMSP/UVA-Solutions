#include <bits/stdc++.h>

typedef unsigned long long int u64;

u64 rev(u64 x) {
    u64 y = 0;
    while (x) {
        y = (y * 10) + (x % 10);
        x /= 10;
    }
    return y;
}

int main() {
    u64 a;
    int n, tt;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%llu", &a);
        n = 0;
        do {
            a = a + rev(a);
            n += 1;
        } while (a != rev(a));
        printf("%d %llu\n", n, a);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Aug-2018
*/
