#include <bits/stdc++.h>

void rotateX(char *d) {
    char tmp = d[0];
    d[0] = d[2];
    d[2] = d[1];
    d[1] = d[4];
    d[4] = tmp;
}

void rotateY(char *d) {
    char tmp = d[2];
    d[2] = d[3];
    d[3] = d[4];
    d[4] = d[5];
    d[5] = tmp;
}

void rotateZ(char *d) {
    char tmp = d[1];
    d[1] = d[3];
    d[3] = d[0];
    d[0] = d[5];
    d[5] = tmp;
}

int main() {
    int tt;
    char a[10], x[10], y[10], z[10];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%s %s", a, x);
        bool equal = false;
        for (int i = 0; i < 4 && !equal; rotateX(x), ++i) {
            if (strcmp(a, x) == 0) equal = true;
            memcpy(y, x, sizeof(x));
            for (int j = 0; j < 4 && !equal; rotateY(y), ++j) {
                if (strcmp(a, y) == 0) equal = true;
                memcpy(z, y, sizeof(y));
                for (int k = 0; k < 4 && !equal; rotateZ(z), ++k) {
                    if (strcmp(a, z) == 0) equal = true;
                }
            }
        }
        puts(equal ? "Equal" : "Not Equal");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 12-July-2018
*/
