#include <bits/stdc++.h>

using namespace std;

int a[1010];

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        while (scanf("%d", a) && a[0]) {
            for (int i = 1; i < n; ++i) {
                scanf("%d", a + i);
            }
            stack< int > station;
            int c = 1;
            bool canArrange = true;
            for (int i = 0; i < n && canArrange; ++i) {
                if (station.empty() || station.top() != a[i]) {
                    while (c <= a[i]) {
                        station.push(c);
                        ++c;
                    }
                }
                if (station.top() == a[i]) {
                    station.pop();
                } else {
                    canArrange = false;
                }
            }
            puts(canArrange ? "Yes" : "No");
        }
        puts("");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 11-Jan-2017
*/
