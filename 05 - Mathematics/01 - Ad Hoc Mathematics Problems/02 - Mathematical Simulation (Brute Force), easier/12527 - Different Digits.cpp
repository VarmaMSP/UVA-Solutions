#include <bits/stdc++.h>

bool check(int n) {
    int s = 0;
    while (n) {
        int d = n % 10;
        if (s & (1 << d)) return false;
        s |= 1 << d;
        n /= 10;
    }
    return true;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int cnt = 0;
        for (int i = n; i <= m; ++i) {
            if (check(i)) cnt += 1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
