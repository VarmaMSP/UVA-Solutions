#include <bits/stdc++.h>

using namespace std;

inline bool isAlpha(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

int main() {
    string line, text = "";
    while (getline(cin, line)) {
        text.push_back(' ');
        for (auto const x: line) {
            if (isAlpha(x)) {
                text.push_back(tolower(x));
            } else {
                text.push_back(' ');
            }
        }
    }
    set< string > words;
    string tmp;
    stringstream sin;
    sin << text;
    while (sin >> tmp) {
        words.insert(tmp);
    }
    for (auto const& w: words) {
        cout << w << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
