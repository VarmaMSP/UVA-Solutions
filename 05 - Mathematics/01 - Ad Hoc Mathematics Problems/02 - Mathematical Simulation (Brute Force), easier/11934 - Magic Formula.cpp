#include <bits/stdc++.h>

int main() {
    int a, b, c, d, l;
    while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &l) && (a|b|c|d|l)) {
        int cnt = 0;
        for (int x = 0; x <= l; ++x) {
            if (abs(a * x * x + b * x + c) % d == 0) {
                cnt += 1;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
