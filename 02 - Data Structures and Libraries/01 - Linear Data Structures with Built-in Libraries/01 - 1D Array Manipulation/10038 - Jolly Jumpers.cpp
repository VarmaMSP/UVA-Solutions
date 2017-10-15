#include <bits/stdc++.h>

using namespace std;

bool flag[3010];

int main() {
    int n, x, y;
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &x);
        for (int i = 1; i < n; ++i) {
            scanf("%d", &y);
            flag[abs(x - y)] = true;
            x = y;
        }
        bool isJolly = true;
        for (int i = 1; i < n; ++i) {
            if (!flag[i]) {
                isJolly = false;
                break;
            }
        }
        printf(isJolly ? "Jolly\n" : "Not jolly\n");
        memset(flag, false, sizeof(flag));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Dec-2016
*/
