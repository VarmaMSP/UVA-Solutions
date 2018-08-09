#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        printf("[%d;", m / n);
        m = m % n;
        while (m > 1) {
            swap(m, n);
            printf("%d,", m / n);
            m = m % n;
        }
        printf("%d]\n", n);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
