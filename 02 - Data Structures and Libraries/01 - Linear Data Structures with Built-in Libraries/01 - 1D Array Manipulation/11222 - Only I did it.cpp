#include <bits/stdc++.h>

int ac, bc, cc;
bool a[10001], b[10001], c[10001];

int main() {
    int tt, n, p, x = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        while (n--) scanf("%d", &p), a[p] = true;
        scanf("%d", &n);
        while (n--) scanf("%d", &p), b[p] = true;
        scanf("%d", &n);
        while (n--) scanf("%d", &p), c[p] = true;
        ac = bc = cc = 0;
        for (int i = 1; i < 10001; ++i) {
            if (a[i] && !b[i] && !c[i]) ac += 1;
            if (!a[i] && b[i] && !c[i]) bc += 1;
            if (!a[i] && !b[i] && c[i]) cc += 1;
        }
        printf("Case #%d:\n", x++);
        if (ac >= bc && ac >= cc) {
            printf("1 %d", ac);
            for (int i = 1; i < 10001; ++i) {
                if (a[i] && !b[i] && !c[i]) printf(" %d", i);
            }
            printf("\n");
        }
        if (bc >= ac && bc >= cc) {
            printf("2 %d", bc);
            for (int i = 1; i < 10001; ++i) {
                if (!a[i] && b[i] && !c[i]) printf(" %d", i);
            }
            printf("\n");
        }
        if (cc >= ac && cc >= bc) {
            printf("3 %d", cc);
            for (int i = 1; i < 10001; ++i) {
                if (!a[i] && !b[i] && c[i]) printf(" %d", i);
            }
            printf("\n");
        }
        memset(a, false, sizeof(a));
        memset(b, false, sizeof(b));
        memset(c, false, sizeof(c));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Aug-2018
*/
