#include <bits/stdc++.h>

using namespace std;

int a[60];

int main() {
    int n, k = 1;
    while (scanf("%d", &n) && n) {
        int h = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            h += a[i];
        }
        h /= n;
        for (int i = 0; i < n; ++i) {
            if (a[i] > h) {
                res += a[i] - h;
            }
        }
        printf("Set #%d\n", k++);
        printf("The minimum number of moves is %d.\n\n", res);
    }
    return 0;
}

/*
Author: bumpy(-_-)
date: 19-Dec-16
*/
