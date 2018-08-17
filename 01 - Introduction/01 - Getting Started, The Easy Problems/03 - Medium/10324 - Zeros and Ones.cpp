#include <bits/stdc++.h>

using namespace std;

char str[1000100];

inline int toInt(char c) {
    return c == '0' ? 0 : 1;
}

int main() {
    int n, x, y, c = 1;
    while (scanf("%s", str) != EOF) {
        scanf("%d", &n);
        printf("Case %d:\n", c++);
        while (n--) {
            scanf("%d %d", &x, &y);
            if (x > y) swap(x, y);
            int s = toInt(str[x]);
            bool equal = true;
            for (int i = x + 1; i <= y; ++i) {
                if (s ^ toInt(str[i])) {
                    equal = false;
                    break;
                }
            }
            puts(equal ? "Yes" : "No");
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-Aug-2018
*/
