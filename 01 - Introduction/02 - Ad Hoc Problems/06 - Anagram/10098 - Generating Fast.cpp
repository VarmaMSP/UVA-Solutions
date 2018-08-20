#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    string str;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        cin >> str;
        sort(str.begin(), str.end());
        do {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end()));
        cout << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Aug-2018
*/
