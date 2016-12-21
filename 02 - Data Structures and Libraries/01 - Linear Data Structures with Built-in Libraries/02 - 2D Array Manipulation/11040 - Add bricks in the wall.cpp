#include <bits/stdc++.h>

using namespace std;

int a[10][10];

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        for (int i = 1; i <= 9; i += 2) {
            for (int j = 1; j <= i; j += 2) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 9; i >= 0; i -= 2) {
            for (int j = 2; j <= i; j += 2) {
                int x = a[i][j - 1];
                int y = a[i][j + 1];
                int z = a[i - 2][j - 1];
                a[i][j] = (z - (x + y)) / 2;
            }
        }
        for (int i = 2; i <= 9; i += 2) {
            for (int j = 1; j <= i; ++j) {
                int x = a[i + 1][j];
                int y = a[i + 1][j + 1];
                a[i][j] = x + y;
            }
        }
        for (int i = 1; i <= 9; ++i) {
            printf ("%d", a[i][1]);
            for (int j = 2; j <= i; ++j) {
                printf (" %d", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Dec-2016
*/
