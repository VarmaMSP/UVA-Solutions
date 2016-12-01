#include <bits/stdc++.h>

typedef long long int i64;

int A[1005][1005];

int main() {
    int n, m;
    bool isFirstLine = false;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &A[i][j]);
                if (i > 0)
                    A[i][j] += A[i - 1][j];
                if (j > 0)
                    A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0)
                    A[i][j] -= A[i - 1][j - 1];
            }
        }
        if (!isFirstLine)
            printf("\n");
        else
            isFirstLine = !isFirstLine;
        i64 sum = 0;
        for (int i = 0; i < n - m + 1; ++i) {
            for (int j = 0; j < n - m + 1; ++j) {
                int k = i + m - 1;
                int l = j + m - 1;
                int temp = A[k][l];
                if (i > 0)
                    temp -= A[i - 1][l];
                if (j > 0)
                    temp -= A[k][j - 1];
                if (i > 0 && j > 0)
                    temp += A[i - 1][j - 1];
                sum += temp;
                printf("%d\n", temp);
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 1-Dec-2016
*/
