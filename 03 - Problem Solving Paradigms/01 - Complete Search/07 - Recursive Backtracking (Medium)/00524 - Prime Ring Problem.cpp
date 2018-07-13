#include <bits/stdc++.h>

int n, a[20];
bool taken[20];

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

void solve(int p) {
    if (p < n) {
        for (int i = 1; i <= n; ++i) {
            if (!taken[i] && isPrime(i + a[p - 1])) {
                taken[i] = true;
                a[p] = i, solve(p + 1);
                taken[i] = false;
            }
        }
        return ;
    }
    if (isPrime(a[0] + a[n - 1])) {
        for (int i = 0; i < n - 1; ++i) {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n - 1]);
    }
}

int main() {
    int x = 1;
    bool first = true;
    a[0] = 1, taken[1] = true;
    while (scanf("%d", &n) != EOF) {
        if (!first) puts("");
        first = false;
        printf("Case %d:\n", x++);
        solve(1);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
