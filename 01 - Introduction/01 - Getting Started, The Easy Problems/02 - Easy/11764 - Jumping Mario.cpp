#include <bits/stdc++.h>

int main() {
    int tt, n, curr, next, i = 1;
    scanf("%d", &tt);
    while (tt--) {
        int high = 0, low = 0;
        scanf("%d %d", &n, &curr);
        n -= 1;
        while (n--) {
            scanf("%d", &next);
            if (next > curr) high += 1;
            if (next < curr) low += 1;
            curr = next;
        }
        printf("Case %d: %d %d\n", i++, high, low);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-Jun-2018
*/
