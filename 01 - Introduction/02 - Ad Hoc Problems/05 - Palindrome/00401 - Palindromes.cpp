#include <bits/stdc++.h>

using namespace std;

char mirror[256];

void preprocess() {
    mirror['A' - '0'] = 'A';
    mirror['E' - '0'] = '3';
    mirror['H' - '0'] = 'H';
    mirror['I' - '0'] = 'I';
    mirror['J' - '0'] = 'L';
    mirror['L' - '0'] = 'J';
    mirror['M' - '0'] = 'M';
    mirror['O' - '0'] = 'O';
    mirror['S' - '0'] = '2';
    mirror['T' - '0'] = 'T';
    mirror['U' - '0'] = 'U';
    mirror['V' - '0'] = 'V';
    mirror['W' - '0'] = 'W';
    mirror['X' - '0'] = 'X';
    mirror['M' - '0'] = 'M';
    mirror['Y' - '0'] = 'Y';
    mirror['Z' - '0'] = '5';
    mirror['1' - '0'] = '1';
    mirror['2' - '0'] = 'S';
    mirror['3' - '0'] = 'E';
    mirror['5' - '0'] = 'Z';
    mirror['8' - '0'] = '8';
}

int main() {
    preprocess();
    string str, rev;
    while (cin >> str) {
        rev.assign(str.rbegin(), str.rend());
        bool isPalin = str == rev;
        bool isMirror = true;
        for (int i = 0; i <= str.size() / 2; ++i) {
            if (mirror[str[i] - '0'] != rev[i]) {
                isMirror = false;
                break;
            }
        }
        if (isPalin && isMirror) cout << str << " -- is a mirrored palindrome.";
        if (!isPalin && isMirror) cout << str << " -- is a mirrored string.";
        if (isPalin && !isMirror) cout << str << " -- is a regular palindrome.";
        if (!isPalin && !isMirror) cout << str << " -- is not a palindrome.";
        cout << endl << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
