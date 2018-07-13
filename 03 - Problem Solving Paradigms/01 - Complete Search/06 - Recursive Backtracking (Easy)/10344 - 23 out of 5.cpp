#include <bits/stdc++.h>

int n[5];
bool taken[5], isPoss;

void solve(int res, int o) {
    if (o > 0) {
        for (int i = 0; i < 5; ++i) if (!taken[i]) {
            taken[i] = true;
            solve(res + n[i], o - 1);
            solve(res - n[i], o - 1);
            solve(res * n[i], o - 1);
            taken[i] = false;
        }
        return ;
    }
    if (res == 23) {
        isPoss = true;
    }
}

int main() {
    while (scanf("%d %d %d %d %d", n, n + 1, n + 2, n + 3, n + 4) && (n[0]|n[1]|n[2]|n[3]|n[4])) {
        isPoss = false;
        for (int i = 0; i < 5 && !isPoss; ++i) {
            taken[i] = true;
            solve(n[i], 4);
            taken[i] = false;
        }
        puts(isPoss ? "Possible" : "Impossible");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
