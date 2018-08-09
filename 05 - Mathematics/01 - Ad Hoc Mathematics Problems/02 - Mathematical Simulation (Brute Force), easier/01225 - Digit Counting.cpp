#include <bits/stdc++.h>

int s[10];

int main() {
    int tt, n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int tmp = i;
            while (tmp) {
                s[tmp % 10] += 1;
                tmp /= 10;
            }
        }
        for (int i = 0; i < 9; ++i) {
            printf("%d ", s[i]);
        }
        printf("%d\n", s[9]);
        memset(s, 0, sizeof(s));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
