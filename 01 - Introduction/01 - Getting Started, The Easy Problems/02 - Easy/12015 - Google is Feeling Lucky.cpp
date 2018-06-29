#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, relevance[10], i = 1;
    string str[10];
    cin >> tt;
    while (tt--) {
        int max = INT_MIN;
        for (int i = 0; i < 10; ++i) {
            cin >> str[i] >> relevance[i];
            if (relevance[i] > max) max = relevance[i];
        }
        cout << "Case #" << i++ << ":" << endl;
        for (int i = 0; i < 10; ++i) {
            if (relevance[i] == max) {
                cout << str[i] << endl;
            }
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 29-Jun-2018
*/
