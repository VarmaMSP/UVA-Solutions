#include <bits/stdc++.h>

int sum(int n) {
    int s = 0;
    for (int m = 1; m < n; ++m) {
        if (n % m == 0) s += m;
    }
    return s;
}

int main() {
    int n;
    puts("PERFECTION OUTPUT");
    while (scanf("%d", &n) && n) {
        int s = sum(n);
        if (s == n) printf("%5d  PERFECT\n", n);
        if (s < n)  printf("%5d  DEFICIENT\n", n);
        if (s > n)  printf("%5d  ABUNDANT\n", n);
    }
    puts("END OF OUTPUT");
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
