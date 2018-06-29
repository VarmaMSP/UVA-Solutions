#include <bits/stdc++.h>

int main() {
    int tt, n, i = 1;
    scanf("%d", &tt);
    while (tt--) {
        int tmp, max = INT_MIN;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &tmp);
            if (tmp > max) max = tmp;
        }
        printf("Case %d: %d\n", i++, max);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-Jun-2018
*/
