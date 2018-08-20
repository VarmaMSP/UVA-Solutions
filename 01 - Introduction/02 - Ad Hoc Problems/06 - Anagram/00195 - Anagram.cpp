#include <bits/stdc++.h>

using namespace std;

bool compare(char x, char y) {
    if (tolower(x) == tolower(y)) return x < y;
    return tolower(x) < tolower(y);
}

int main() {
    int tt;
    string str;
    cin >> tt;
    while (tt--) {
        cin >> str;
        sort(str.begin(), str.end(), compare);
        do {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end(), compare));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 20-Aug-2018
*/
