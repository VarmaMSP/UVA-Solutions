#include <bits/stdc++.h>

using namespace std;

int p[30010];

int find_set(int x) {
    if (p[x] != x) {
        p[x] = find_set(p[x]);
    }
    return p[x];
}

int main() {
    int n, m, k, s;
    while (scanf("%d %d", &n, &m) && n|m) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        while (m--) {
            scanf("%d %d", &k, &s);
            k -= 1;
            int X = find_set(s);
            while (k--) {
                scanf("%d", &s);
                int Y = find_set(s);
                if (X != Y) {
                    p[Y] = X;
                }
            }
        }
        int cnt = 0;
        int X = find_set(0);
        for (int i = 0; i < n; ++i) {
            if (find_set(i) == X) {
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 21-Dec-2016
*/
