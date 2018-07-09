#include <bits/stdc++.h>

int ind(char bin) {
    switch (bin) {
        case 'r': return 0;
        case 'o': return 1;
        case 'y': return 2;
        case 'g': return 3;
        case 'b': return 4;
    }
}

int main() {
    char str[20], city[110][5];
    while (scanf("%s", str) && str[0] != '#') {
        int n = 0;
        do {
            city[n][ind(str[0])] = str[2];
            city[n][ind(str[4])] = str[6];
            city[n][ind(str[8])] = str[10];
            city[n][ind(str[12])] = str[14];
            city[n][ind(str[16])] = str[18];
            n += 1;
        } while (scanf("%s", str) && str[0] != 'e');
        int min = INT_MAX, res;
        for (int i = 0; i < n; ++i) {
            int changes = 0;
            for (int j = 0; j < n; ++j) if (i != j) {
                for (int k = 0; k < 5; ++k) if (city[i][k] != city[j][k]) {
                    changes += 1;
                }
            }
            if (changes < min) {
                min = changes;
                res = i;
            }
        }
        printf("%d\n", res + 1);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 6-July-2018
*/
