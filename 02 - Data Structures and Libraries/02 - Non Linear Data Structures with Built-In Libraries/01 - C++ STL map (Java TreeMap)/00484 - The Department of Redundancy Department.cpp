#include <bits/stdc++.h>

using namespace std;

vector< int > L;
map< int, int > cnt;

int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        if (cnt.find(a) == cnt.end()) {
            L.push_back(a);
        }
        cnt[a] += 1;
    }
    for (auto x: L) {
        printf("%d %d\n", x, cnt[x]);
    }
}

/*
Author: bumpy(-_-)
date: 12-Jan-2017
*/
