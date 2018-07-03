#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

int main() {
    int tt;
    i64 a, b, c, d, e, f;
    string line;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        a = 0, c = 1;
        e = 1, f = 1;
        b = 1, d = 0;
        getline(cin, line);
        for (auto const x: line) {
            if (x == 'L') b = e, d = f;
            if (x == 'R') a = e, c = f;
            e = a + b, f = c + d;
        }
        cout << e << '/' << f << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 3-July-2018
*/
