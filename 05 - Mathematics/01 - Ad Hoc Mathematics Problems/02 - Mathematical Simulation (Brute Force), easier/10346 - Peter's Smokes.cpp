#include <bits/stdc++.h>

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        int res = n;
        while (n >= k) {
            res += n / k;
            n = (n / k) + (n % k);
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
