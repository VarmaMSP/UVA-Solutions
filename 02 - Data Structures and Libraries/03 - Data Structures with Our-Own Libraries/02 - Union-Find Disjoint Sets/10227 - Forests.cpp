#include <bits/stdc++.h>

using namespace std;

int p[110];
set< int > trees[110];

int find_set(int x) {
    if (p[x] != x) {
        p[x] = find_set(p[x]);
    }
    return p[x];
}

int main() {
    int tt, person, tree, P, T;
    char tmp[100];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d\n", &P, &T);
        for (int i = 1; i <= P; ++i) {
            p[i] = i;
        }

        while (gets(tmp) && tmp[0]) {
            sscanf(tmp, "%d %d", &person, &tree);
            trees[person].insert(tree);
        }

        for (int i = 1; i <= P; ++i) {
            for (int j = i + 1; j <= P; ++j) {
                if (trees[i] == trees[j]) {
                    int X = find_set(i);
                    int Y = find_set(j);
                    if (X != Y) {
                        p[Y] = X;
                    }
                }
            }
        }

        int opinions = 0;
        for (int i = 1; i <= P; ++i) {
            if (p[i] == i) {
                ++opinions;
            }
        }

        printf("%d\n", opinions);
        if (tt) {
            printf("\n");
        }

        for (int i = 1; i <= P; ++i) {
            trees[i].clear();
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 21-Dec-2016
*/
