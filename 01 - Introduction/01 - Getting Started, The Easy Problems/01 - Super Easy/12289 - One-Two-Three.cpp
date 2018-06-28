#include <bits/stdc++.h>

int char_mismatch_count(char *correct, char *input) {
    int cnt = 0;
    while (*correct && *input) {
        if (*correct != *input) cnt += 1;
        correct += 1;
        input += 1;
    }
    return cnt;
}

int main() {
    int tt;
    char str[10];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%s", str);
        if (char_mismatch_count("one", str) <= 1) puts("1");
        if (char_mismatch_count("two", str) <= 1) puts("2");
        if (char_mismatch_count("three", str) <= 1) puts("3");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
