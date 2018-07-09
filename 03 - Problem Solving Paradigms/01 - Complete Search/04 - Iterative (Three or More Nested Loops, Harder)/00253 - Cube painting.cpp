#include <bits/stdc++.h>

void rotateX(char *d) {
    char tmp = d[0];
    d[0] = d[4];
    d[4] = d[5];
    d[5] = d[1];
    d[1] = tmp;
}

void rotateY(char *d) {
    char tmp = d[1];
    d[1] = d[2];
    d[2] = d[4];
    d[4] = d[3];
    d[3] = tmp;
}

void rotateZ(char *d) {
    char tmp = d[0];
    d[0] = d[3];
    d[3] = d[5];
    d[5] = d[2];
    d[2] = tmp;
}

int main() {
    char str[15], a[8], x[8], y[8], z[8];
    while (scanf("%s", str) != EOF) {
        for (int i = 0; i < 6; ++i) {
            a[i] = str[i];
            x[i] = str[i + 6];
        }
        a[6] = x[6] = '\0';
        bool same = false;
        for (int i = 0; i < 4 && !same; rotateX(x), ++i) {
            if (strcmp(a, x) == 0) same = true;
            memcpy(y, x, sizeof(x));
            for (int j = 0; j < 4 && !same; rotateY(y), ++j) {
                if (strcmp(a, y) == 0) same = true;
                memcpy(z, y, sizeof(y));
                for (int k = 0; k < 4 && !same; rotateZ(z), ++k) {
                    if (strcmp(a, z) == 0) same = true;
                }
            }
        }
        puts(same ? "TRUE" : "FALSE");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-July-2018
*/
