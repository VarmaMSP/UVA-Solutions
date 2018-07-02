#include <bits/stdc++.h>

using namespace std;

inline bool isAlpha(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

int main() {
    bool hyphen = false;
    string line, text = "";
    while (getline(cin, line)) {
        if (!hyphen) {
            text.push_back(' ');
        }
        hyphen = *line.rbegin() == '-';
        if (hyphen) {
            line.erase(prev(line.end()));
        }
        for (auto const x: line) {
            if (isAlpha(x)) {
                text.push_back(tolower(x));
            } else if (x == '-') {
                text.push_back('-');
            } else {
                text.push_back(' ');
            }
        }
    }
    set< string > words;
    stringstream sin;
    string tmp;
    sin << text;
    while (sin >> tmp) {
        words.insert(tmp);
    }
    for (auto const &w: words) {
        cout << w << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
