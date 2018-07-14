#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, x, a[10100], c = 1;
    while (scanf("%d %d", &n, &q) && (n|q)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        sort(a, a + n);
        printf("CASE# %d:\n", c++);
        while (q--) {
            scanf("%d", &x);
            int p = distance(a, lower_bound(a, a + n, x));
            if (p < n && a[p] == x) {
                printf("%d found at %d\n", x, p + 1);
            } else {
                printf("%d not found\n", x);
            }
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 14-July-2018
*/
