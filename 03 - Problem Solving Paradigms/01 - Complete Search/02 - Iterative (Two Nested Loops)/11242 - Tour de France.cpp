#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, r, m[11], n[11];
    double d[110];
    while (scanf("%d", &f) && f) {
        scanf("%d", &r);
        for (int i = 0; i < f; ++i) scanf("%d", m + i);
        for (int i = 0; i < r; ++i) scanf("%d", n + i);
        int k = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < f; ++j) {
                d[k++] = (double)n[i] / (double)m[j];
            }
        }
        sort(d, d + k);
        double res = -1.0;
        for (int i = 0; i < k - 1; ++i) {
            res = max(res, d[i + 1] / d[i]);
        }
        printf("%.2lf\n", res);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
