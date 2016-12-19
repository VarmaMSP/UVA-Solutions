#include <bits/stdc++.h>

using namespace std;

int a[550];

int main() {
    int tt, r;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &r);
        for (int i = 0; i < r; ++i) {
            scanf("%d", a + i);
        }
        int res = INT_MAX;
        for (int i = 0; i < r; ++i) {
            int tmp = 0;
            for (int j = 0; j < r; ++j) {
                tmp += abs(a[i] - a[j]);
            }
            res = min(res, tmp);
        }
        printf("%d\n", res);
    }
    return 0;
}


/*
Author: bumpy(-_-)
date: 19-Dec-2016
*/
