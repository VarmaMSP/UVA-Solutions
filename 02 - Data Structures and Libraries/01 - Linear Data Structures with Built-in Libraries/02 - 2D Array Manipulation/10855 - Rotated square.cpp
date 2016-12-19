#include <bits/stdc++.h>

using namespace std;

int N, n;
char M[500][500], m[500][500];

int searchMatrix() {
    int cnt = 0;
    for (int i = 0; i <= N - n; ++i) {
        for (int j = 0; j <= N - n; ++j) {
            bool present = true;
            for (int k = 0; k < n && present; ++k) {
                for (int l = 0; l < n && present; ++l) {
                    if (M[i + k][j + l] != m[k][l]) {
                        present = false;
                    }
                }
            }
            if (present) {
                ++cnt;
            }
        }
    }
    return cnt;
}

void rotateMatrix() {
    for (int x = 0; x < n / 2; ++x) {
        int X = n - x - 1;
        for (int y = x; y < X; ++y) {
            int Y = n - y - 1;
            int tmp = m[x][y];
            m[x][y] = m[Y][x];
            m[Y][x] = m[X][Y];
            m[X][Y] = m[y][X];
            m[y][X] = tmp;
        }
    }
}

int main() {
    char tmp[20];
    while (sscanf(gets(tmp), "%d %d", &N, &n) && n|N) {
        for (int i = 0; i < N; ++i) {
            gets(M[i]);
        }
        for (int i = 0; i < n; ++i) {
            gets(m[i]);
        }
        printf("%d", searchMatrix());
        for (int i = 0; i < 3; ++i) {
            rotateMatrix();
            printf(" %d", searchMatrix());
        }
        printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Dec-2016
*/
