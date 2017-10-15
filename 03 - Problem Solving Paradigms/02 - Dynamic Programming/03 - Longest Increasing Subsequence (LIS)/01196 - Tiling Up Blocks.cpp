#include <bits/stdc++.h>

using namespace std;

pair< int, int > A[10100];
int LIS[10100];

int main() {
    int n, x, y;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            A[i] = {x, y};
        }
        sort(A, A + n);
        for (int i = 0; i < n; ++i) {
            int tmp = 0;
            for (int j = 0; j < i; ++j) {
                if (A[j].second <= A[i].second && LIS[j] > tmp) {
                    tmp = LIS[j];
                }
            }
            LIS[i] = 1 + tmp;
        }
        printf("%d\n", *max_element(LIS, LIS + n));
    }
    printf("*\n");
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-12-2016
*/
