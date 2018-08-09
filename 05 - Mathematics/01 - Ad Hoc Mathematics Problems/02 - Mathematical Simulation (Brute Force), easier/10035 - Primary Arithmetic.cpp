#include <bits/stdc++.h>

int main() {
    int a, b, c, res, m, n;
    while (scanf("%d %d", &m, &n) && (m|n)) {
        c = 0;
        res = 0;
        while (m || n) {
            res += c;
            a = m % 10, m /= 10;
            b = n % 10, n /= 10;
            c = (a + b + c) / 10;
        }
        res += c;
        if (res == 0) puts("No carry operation.");
        if (res == 1) puts("1 carry operation.");
        if (res > 1)  printf("%d carry operations.\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
