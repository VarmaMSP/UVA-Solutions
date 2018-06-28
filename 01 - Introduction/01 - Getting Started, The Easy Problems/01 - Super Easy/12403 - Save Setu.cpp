#include <bits/stdc++.h>

int main() {
    int tt, donation, total = 0;
    char cmd[10];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%s", cmd);
        if (strcmp(cmd, "donate") == 0) {
            scanf("%d", &donation);
            total += donation;
        }
        if (strcmp(cmd, "report") == 0) {
            printf("%d\n", total);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
