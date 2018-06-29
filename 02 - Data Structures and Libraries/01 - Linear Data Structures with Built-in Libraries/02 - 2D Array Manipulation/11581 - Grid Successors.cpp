#include <bits/stdc++.h>

void f(int a[5][5]) {
    int b[5][5];
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            b[i][j] = a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1];
            b[i][j] %= 2;
        }
    }
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            a[i][j] = b[i][j];
        }
    }
}

bool isZero(int a[5][5]) {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (a[i][j]) return false;
        }
    }
    return true;
}

int main() {
    int tt, g[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            g[i][j] = 0;
        }
    }
    scanf("%d", &tt);
    while (tt--) {
        char tmp[5];
        for (int i = 0; i < 3; ++i) {
            scanf("%s", tmp);
            for (int j = 0; j < 3; ++j) {
                g[i + 1][j + 1] = tmp[j] == '0' ? 0 : 1;
            }
        }
        int i = 0;
        while (!isZero(g)) {
            f(g); i += 1;
        }
        printf("%d\n", i - 1);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-Jun-2018
*/
