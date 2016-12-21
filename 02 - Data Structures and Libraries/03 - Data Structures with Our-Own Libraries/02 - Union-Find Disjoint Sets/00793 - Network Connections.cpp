#include <bits/stdc++.h>

using namespace std;

int n, p[10000];

int find_set(int x) {
    if (p[x] != x) {
        p[x] = find_set(p[x]);
    }
    return p[x];
}

int main() {
    int tt, x, y;
    char tmp[30], op;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d\n", &n);
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        int success = 0, unsuccess = 0;
        while (gets(tmp) && tmp[0]) {
            sscanf(tmp, "%c %d %d", &op, &x, &y);

            int X = find_set(x);
            int Y = find_set(y);
            switch (op) {
                case 'c':
                    if (X != Y) {
                        p[Y] = X;
                    }
                    break;
                case 'q':
                    if (X != Y) {
                        unsuccess += 1;
                    } else {
                        success += 1;
                    }
                    break;
            }
        }
        printf("%d,%d\n", success, unsuccess);
        if (tt) {
            printf("\n");
        }
    }
    return 0;
}

/*
Author: bumpy(-_-)
date: 21-Dec-2016
*/
