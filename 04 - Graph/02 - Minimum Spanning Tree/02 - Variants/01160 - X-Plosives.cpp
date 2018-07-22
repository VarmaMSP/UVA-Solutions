#include <bits/stdc++.h>

int p[100100];

int find_set(int x) {
    if (p[x] !=  x)
        p[x] = find_set(p[x]);
    return p[x];
}

int main() {
    int x, y;
    while (scanf("%d", &x) != EOF) {
        for (int i = 0; i < 100100; ++i) {
            p[i] = i;
        }
        int res = 0;
        do {
            scanf("%d", &y);
            int X = find_set(x);
            int Y = find_set(y);
            if (X != Y) {
                p[Y] = X;
            } else {
                res += 1;
            }
        } while (scanf("%d", &x) && x != -1);
        printf("%d\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 22-Jul-2018
*/
