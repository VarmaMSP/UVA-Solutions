#include <bits/stdc++.h>

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        int res = 0;
        while (n >= 3) {
            res += n / 3;
            n = (n / 3) + (n % 3);
        }
        if (n == 2) {
            res += 1;
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
