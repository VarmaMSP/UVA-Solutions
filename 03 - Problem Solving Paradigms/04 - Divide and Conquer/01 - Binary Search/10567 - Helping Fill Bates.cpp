#include <bits/stdc++.h>

using namespace std;

inline int ind(char a) {
  if ('a' <= a && a <= 'z') return a - 'a';
  if ('A' <= a && a <= 'Z') return 26 + (a - 'A');
}

int main() {
    int q;
    string str;
    vector< int > country[55];
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        country[ind(str[i])].push_back(i);
    }
    cin >> q;
    while (q--) {
        cin >> str;
        int x, y = -1;
        bool isMatch = true;
        for (int i = 0; i < str.size() && isMatch; ++i) {
            vector< int > c = country[ind(str[i])];
            auto d = upper_bound(c.begin(), c.end(), y);
            if (d != c.end()) {
                y = *d;
                if (i == 0) x = y;
            } else {
                isMatch = false;
            }
        }
        if (isMatch) {
            cout << "Matched " << x << " " << y << endl;
        } else {
            cout << "Not matched" << endl;
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 16-July-2018
*/
