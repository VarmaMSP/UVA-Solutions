#include <bits/stdc++.h>

using namespace std;

int ind[5050];
string a[5050];

int main() {
    int tt, i;
    string str;
    stringstream ss;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        cin.ignore();
        getline(cin, str);
        ss.clear();
        ss << str;
        for (i = 0; ss >> ind[i]; ++i);
        getline(cin, str);
        ss.clear();
        ss << str;
        for (i = 0; ss >> a[ind[i] - 1]; ++i);
        for (int j = 0; j < i; ++j) {
            cout << a[j] << endl;
        }
        if (tt) cout << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Aug-2018
*/
