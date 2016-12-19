#include <bits/stdc++.h>

using namespace std;

int r[110], c[110];

int main() {
    int n, v;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &v);
                r[i] += v;
                c[j] += v;
            }
        }
        int x, y;
        int rc = 0, cc = 0;
        bool parity = true;
        for (int i = 0; i < n; ++i) {
            if (r[i] & 1) {
                parity = false;
                x = i;
                ++rc;
            }
            if (c[i] & 1) {
                parity = false;
                y = i;
                ++cc;
            }
        }
        if (parity) {
            printf("OK\n");
        } else {
            if (rc == 1 && cc == 1)
                printf("Change bit (%d,%d)\n", x + 1, y + 1);
            else
                printf("Corrupt\n");
        }
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Dec-2016
*/
