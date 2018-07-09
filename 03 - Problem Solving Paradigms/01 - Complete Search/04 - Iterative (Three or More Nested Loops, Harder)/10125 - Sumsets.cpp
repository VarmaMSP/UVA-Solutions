#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, arr[1010];
    while (scanf("%d", &n) && n > 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", arr + i);
        }
        sort(arr, arr + n);
        bool found = false;
        for (int d = n - 1; d >= 0 && !found; --d) {
            for (int a = 0; a < n && !found; ++a) if (a != d) {
                for (int b = a + 1; b < n && !found; ++b) if (b != d) {
                    for (int c = b + 1; c < n && !found; ++c) if (c != d) {
                        if (arr[a] + arr[b] + arr[c] == arr[d]) {
                            found = true;
                            printf("%d\n", arr[d]);
                        }
                    }
                }
            }
        }
        if (!found) puts("no solution");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-July-2018
*/
