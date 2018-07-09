#include <bits/stdc++.h>

typedef long long i64;

int main() {
    int n, a[20], c = 1;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        i64 max = 0;
        for (int i = 0; i < n; ++i) {
            i64 p = a[i];
            if (p > max) max = p;
            for (int j = i + 1; j < n; ++j) {
                p *= a[j];
                if (p > max) max = p;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", c++, max);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 6-July-2018
*/
