#include <bits/stdc++.h>

int main() {
    int tt, s, niceness, route = 1;
    scanf("%d", &tt);
    while (tt--) {
        int sum = 0, res = 0;
        int temp = 1, start, stop;
        scanf("%d", &s);
        for (int i = 1; i < s; ++i) {
            scanf("%d", &niceness);
            sum += niceness;
            if (sum < 0) {
                sum = 0;
                temp = i + 1;
                continue;
            }
            if (sum > res) {
                res = sum;
                start = temp;
                stop = i + 1;
                continue;
            }
            if (sum == res && (i - temp + 1) > (stop - start)) {
                start = temp;
                stop = i + 1;
                continue;
            }
        }
        if (res > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", route, start, stop);
        else
            printf("Route %d has no nice parts\n", route);
        ++route;
    }
}

//Date: 30 Nov, 2016
//Author: bumpy -_-
