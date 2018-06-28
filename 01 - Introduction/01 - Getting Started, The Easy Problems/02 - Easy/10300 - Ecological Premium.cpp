#include <bits/stdc++.h>

int main() {
    int tt, f, s, n, e;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &f);
        int budget = 0;
        while (f--) {
            scanf("%d %d %d", &s, &n, &e);
            budget += s * e;
        }
        printf("%d\n", budget);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
