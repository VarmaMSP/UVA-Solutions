#include <bits/stdc++.h>

using namespace std;

long long int a[110][110];

int main() {
    char p, q;
    int tt, n, k = 1;
    scanf("%d", &tt);
    while (tt--) {
        for (int i = 0; i < 4; ++i)
            getchar();
        scanf("%d", &n);

        bool isSymmetric = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%lld", &a[i][j]);
                if (a[i][j] < 0) {
                    isSymmetric = false;
                }
            }
        }
        for (int x = 0; x < n && isSymmetric; ++x) {
            for (int y = 0; y < n && isSymmetric; ++y) {
                if (a[x][y] != a[n - x - 1][n - y - 1]) {
                    isSymmetric = false;
                }
            }
        }

        printf ("Test #%d: ", k++);
        if (isSymmetric)
            printf("Symmetric.\n");
        else
            printf("Non-symmetric.\n");
    }
    return 0;
}

/*
Author: (-_-)
date: 19-Dec-2016
*/
