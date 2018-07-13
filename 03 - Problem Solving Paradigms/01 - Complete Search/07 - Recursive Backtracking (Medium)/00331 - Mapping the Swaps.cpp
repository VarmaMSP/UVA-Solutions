#include <bits/stdc++.h>

using namespace std;

int n, a[10], c = 0, l = 0;

void solve() {
    bool sorted = true;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            sorted = false;
            swap(a[i], a[i + 1]), l += 1;
            solve();
            swap(a[i], a[i + 1]), l -= 1;
        }
    }
    if (sorted && l > 0) c += 1;
}

int main() {
    int x = 1;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        c = 0;
        solve();
        printf("There are %d swap maps for input data set %d.\n", c, x++);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
