#include <bits/stdc++.h>

int main() {
    int tt, n, max, min, tmp;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        max = INT_MIN;
        min = INT_MAX;
        while (n--) {
            scanf("%d", &tmp);
            if (tmp > max) max = tmp;
            if (tmp < min) min = tmp;
        }
        printf("%d\n", (max - min) * 2);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
