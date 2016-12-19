#include <bits/stdc++.h>

using namespace std;

void strrev(char *x, char *y) {
    y -= 1;
    while (x < y) {
        char tmp = *x;
        *x = *y;
        *y = tmp;
        ++x;
        --y;
    }
}

int main() {
    int n;
    char str[110];
    char *start, *stop;
    while (scanf("%d ", &n) && n) {
        gets(str);
        start = stop = str;
        int l = strlen(str) / n;
        int cnt = 0;
        while (*stop) {
            if (cnt == l) {
                strrev(start, stop);
                start = stop;
                cnt = 0;
            }
            ++cnt;
            ++stop;
        }
        strrev(start, stop);
        puts(str);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 19-Dec-2016
*/
