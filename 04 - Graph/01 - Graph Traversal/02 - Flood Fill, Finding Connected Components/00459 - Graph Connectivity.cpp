#include <bits/stdc++.h>

using namespace std;

int p[100];

inline int toInt(char a) {
    return (int)(a - 'A');
}

int find_set(int x) {
    if (p[x] != x) {
        p[x] = find_set(p[x]);
    }
    return p[x];
}

int main() {
    int tt;
    char n, str[4];
    scanf("%d\n\n", &tt);
    while (tt--) {
        sscanf(gets(str), "%c", &n);
        for(int i = 0; i <= toInt(n); ++i) {
            p[i] = i;
        }
        while (gets(str) && str[0]) {
            int x = find_set(toInt(str[0]));
            int y = find_set(toInt(str[1]));
            if (x != y)
                p[y] = x;
        }
        int cnt = 0;
        for (int i = 0; i <= toInt(n); ++i) {
            if(p[i] == i) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
        if (tt) {
            printf("\n");
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 11-Dec-2016
*/
