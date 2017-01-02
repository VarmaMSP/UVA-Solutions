#include <bits/stdc++.h>

using namespace std;

int a[1000010];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        sort(a, a + n);
        if (n & 1) {
            int A = a[n/2];
            int x = distance(a, lower_bound(a, a + n, A));
            int y = distance(a, upper_bound(a, a + n, A));
            int cnt = y - x;
            printf("%d %d 1\n", A, cnt);
        } else {
            int A = a[n/2 - 1];
            int B = a[n/2];
            int x = distance(a, lower_bound(a, a + n, A));
            int y = distance(a, upper_bound(a, a + n, A));
            int cnt = y - x;
            if (A != B) {
                x = distance(a, lower_bound(a, a + n, B));
                y = distance(a, upper_bound(a, a + n, B));
                cnt += y - x;
            }
            printf("%d %d %d\n", A, cnt, B - A + 1);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 02-Jan-17
*/
