#include <bits/stdc++.h>

using namespace std;

int p[100100];
int s[100100];

int find_set(int x) {
    if (p[x] != x) {
        p[x] = find_set(p[x]);
    }
    return p[x];
}

int main() {
    int tt, f;
    string a, b;
    cin >> tt;
    while (tt--) {
        map< string, int > names;
        cin >> f;
        int c = 1;
        while (f--) {
            cin >> a >> b;
            if (names[a] == 0) names[a] = p[c] = c, s[c] = 1, ++c;
            if (names[b] == 0) names[b] = p[c] = c, s[c] = 1, ++c;
            int x = find_set(names[a]);
            int y = find_set(names[b]);
            if (x != y) {
                p[y] = x;
                s[x] += s[y];
            }
            cout << s[x] << endl;
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 3-July-2018
*/
