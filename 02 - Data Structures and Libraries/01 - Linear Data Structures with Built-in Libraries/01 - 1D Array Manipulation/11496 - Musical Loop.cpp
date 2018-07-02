#include <bits/stdc++.h>

int main() {
    int n, h[10010];
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", h + i);
        }
        int peaks = 0;
        for (int i = 0; i < n; ++i) {
            int a = (i - 1 + n) % n;
            int b = (i + 1) % n;
            if (h[a] < h[i] && h[i] > h[b]) peaks += 1;
            if (h[a] > h[i] && h[i] < h[b]) peaks += 1;
        }
        printf("%d\n", peaks);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
