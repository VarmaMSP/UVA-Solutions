#include <bits/stdc++.h>

using namespace std;

int A[101][101];

int main() {
    int n;
    scanf("%d", &n);
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
    int res = INT_MIN;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        for (int k = i; k < n; ++k) for (int l = j; l < n; ++l) {
            int temp = A[k][l];
            if (i > 0)
                temp -= A[i - 1][l];
            if (j > 0)
                temp -= A[k][j - 1];
            if (i > 0 && j > 0)
                temp += A[i - 1][j - 1];
            res = max(res, temp);
        }
    }
    printf("%d\n", res);
    return 0;
}

//Date: 30 Nov, 2016
//Author: bumpy -_-
