#include <bits/stdc++.h>

using namespace std;

int a[55][55], n;

void swapRow(int x, int y) {
    for (int i = 0; i < n; ++i) {
        swap(a[x][i], a[y][i]);
    }
}

void swapColumn(int x, int y) {
    for (int i = 0; i < n; ++i) {
        swap(a[i][x], a[i][y]);
    }
}

void add(int x) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = (a[i][j] + x + 10) % 10;
        }
    }
}

void transpose() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(a[i][j], a[j][i]);
        }
    }
}

int main() {
    int tt, m, x, y, k = 1;
    char tmp[12];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d\n", &n);
        for (int i = 0; i < n; ++i) {
            gets(tmp);
            for (int j = 0; j < n; ++j) {
                a[i][j] = tmp[j] - '0';
            }
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%s", tmp);
            switch (tmp[0]) {
                case 'r':
                    scanf("%d %d", &x, &y);
                    swapRow(x - 1, y - 1);
                    break;
                case 'c':
                    scanf("%d %d", &x, &y);
                    swapColumn(x - 1, y - 1);
                    break;
                case 'i':
                    add(1);
                    break;
                case 'd':
                    add(-1);
                    break;
                case 't':
                    transpose();
                    break;
            }
        }

        printf("Case #%d\n", k++);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

/*
Author: bumpy(-_-)
date: 20-Dec-2016
*/
