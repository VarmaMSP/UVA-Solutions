#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n != 1 || m != 1)) {
        int a = 0, b = 1;
        int e = 1, f = 1;
        int c = 1, d = 0;
        string res;
        while (true) {
            if (n * f < e * m) {
                res.push_back('L');
                c = e, d = f;
                e = a + c, f = b + d;
            }
            if (n * f > e * m) {
                res.push_back('R');
                a = e, b = f;
                e = a + c, f = b + d;
            }
            if ( n * f == e * m) {
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 16-July-2018
*/
