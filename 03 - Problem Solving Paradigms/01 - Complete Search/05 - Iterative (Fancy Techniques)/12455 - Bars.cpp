#include <bits/stdc++.h>

int main() {
    int tt, n, p, l[22];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p; ++i) {
            scanf("%d", l + i);
        }
        bool found = false;
        for (int s = 0; s < (1 << p) && !found; ++s) {
            int sum = 0;
            for (int i = 0; i < p && !found; ++i) {
                if (s & (1 << i)) sum += l[i];
            }
            if (sum == n) found = true;
        }
        puts(found ? "YES" : "NO");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-July-2018
*/
