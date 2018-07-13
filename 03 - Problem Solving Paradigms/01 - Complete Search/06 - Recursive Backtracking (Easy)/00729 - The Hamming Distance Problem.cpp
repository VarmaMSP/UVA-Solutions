#include <bits/stdc++.h>

using namespace std;

int n, h;
string s;
vector< string > res;

void genComb(int i, int rem) {
    if (i < n) {
        if (rem > 0) {
            s[i] = '1';
            genComb(i + 1, rem - 1);
            s[i] = '0';
        }
        genComb(i + 1, rem);
        return ;
    }
    if (rem == 0) res.push_back(string(s));
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> h;
        for (int i = 0; i < n; ++i) {
            s.push_back('0');
        }
        genComb(0, h);
        for (int i = res.size() - 1; i >= 0; --i) {
            cout << res[i] << endl;
        }
        if (tt) cout << endl;
        res.clear();
        s.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
