#include <bits/stdc++.h>

using namespace std;

int order[24];
int event[24], LIS[24];

int main() {
    int n, tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", order + i);
    }
    while (scanf("%d", &tmp) != EOF) {
        event[tmp] = 1;
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &tmp);
            event[tmp] = i;
        }
        for (int i = 1; i <= n; ++i) {
            tmp = 0;
            for (int j = 1; j < i; ++j) {
                if (order[event[j]] < order[event[i]] && LIS[j] > tmp)
                    tmp = LIS[j];
            }
            LIS[i] = tmp + 1;
        }
        printf("%d\n", *max_element(LIS + 1, LIS + n + 1));
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 1-Dec-2016
*/
