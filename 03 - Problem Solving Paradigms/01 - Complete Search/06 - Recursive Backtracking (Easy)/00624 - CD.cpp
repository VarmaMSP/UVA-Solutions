#include <bits/stdc++.h>

using namespace std;

int n, t, d[22], minD;
vector< int > res, aux;

void place(int i, int rem) {
    if (i < t) {
        if (d[i] <= rem) {
            aux.push_back(d[i]);
            place(i + 1, rem - d[i]);
            aux.pop_back();
        }
        place(i + 1, rem);
        return ;
    }
    if (rem <= minD) {
        minD = rem;
        res = aux;
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        scanf("%d", &t);
        for (int i = 0; i < t; ++i) {
            scanf("%d", d + i);
        }
        minD = INT_MAX;
        place(0, n);
        for (auto const& x: res) {
            printf("%d ", x);
        }
        printf("sum:%d\n", n - minD);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
