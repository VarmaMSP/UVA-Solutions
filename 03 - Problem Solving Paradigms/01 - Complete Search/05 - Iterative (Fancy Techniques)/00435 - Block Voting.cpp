#include <bits/stdc++.h>

int main() {
    int tt, p, v[21], ind[21];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &p);
        int total = 0;
        for (int i = 0; i < p; ++i) {
            scanf("%d", v + i);
            total += v[i];
        }
        memset(ind, 0, sizeof(ind));
        for (int s = 0; s < (1 << p); ++s) {
            int votes = 0;
            for (int i = 0; i < p; ++i) {
                if (s & (1 << i)) votes += v[i];
            }
            if (2 * votes < total) {
                for (int i = 0; i < p; ++i) if (!(s & (1 << i))) {
                    if (2 * (votes + v[i]) >= total) ind[i] += 1;
                }
            }
        }
        for (int i = 0; i < p; ++i) {
            printf("party %d has power index %d\n", i + 1, ind[i]);
        }
        puts("");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-July-2018
*/
