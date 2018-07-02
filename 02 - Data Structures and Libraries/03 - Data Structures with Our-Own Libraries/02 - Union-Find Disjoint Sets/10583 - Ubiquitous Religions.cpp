#include <bits/stdc++.h>

int p[50050];

int find_set(int x) {
    if (p[x] != x) {
        p[x] = find_set(p[x]);
    }
    return p[x];
}

int main() {
    int n, m, a, b, i = 1;
    while (scanf("%d %d", &n, &m) && n|m) {
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        while (m--) {
            scanf ("%d %d", &a, &b);
            int x = find_set(a);
            int y = find_set(b);
            if (x != y) {
                p[y] = x;
            }
        }
        int groups = 0;
        for (int i = 1; i <= n; ++i) {
            if (p[i] == i) {
                groups += 1;
            }
        }
        printf("Case %d: %d\n", i++, groups);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
