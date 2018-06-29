#include <bits/stdc++.h>

bool isAscending(int *a, int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isDescending(int *a, int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int tt, l[10];
    scanf("%d", &tt);
    puts("Lumberjacks:");
    while (tt--) {
        for (int i = 0; i < 10; ++i) {
            scanf("%d", l + i);
        }
        if (isAscending(l, 10) || isDescending(l, 10)) {
            puts("Ordered");
        } else {
            puts("Unordered");
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-Jun-2018
*/
