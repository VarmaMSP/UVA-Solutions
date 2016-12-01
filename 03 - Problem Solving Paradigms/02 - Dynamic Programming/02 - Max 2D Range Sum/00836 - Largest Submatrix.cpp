#include <bits/stdc++.h>

using namespace std;

const int INF = 25 * 25;
int A[25][25];

int input() {
    char str[26];
    scanf("%s", str);
    int l = strlen(str);
    for (int i = 0; i < l; ++i) {
        A[0][i] = (str[i] == '0' ? -INF : 1);
    }
    for (int i = 1; i < l; ++i) {
        scanf("%s", str);
        for (int j = 0; j < l; ++j) {
            A[i][j] = (str[j] == '0' ? -INF : 1);
        }
    }
    return l;
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n = input();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
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
        if (res <= 0)
            printf("0\n");
        else
            printf("%d\n", res);
        if (tt)
            printf("\n");
    }
    return 0;
}

//Date: 30 Nov, 2016
//Author: bumpy -_-
