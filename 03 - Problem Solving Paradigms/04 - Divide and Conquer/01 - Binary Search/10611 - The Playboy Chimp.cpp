#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q, x, a[50100];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        int low = distance(a, lower_bound(a, a + n, x));
        if (low > 0) {
            printf("%d ", a[low - 1]);
        } else {
            printf("X ");
        }
        int up = distance(a, upper_bound(a, a + n, x));
        if (up < n) {
            printf("%d\n", a[up]);
        } else {
            printf("X\n");
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 14-July-2018
*/
