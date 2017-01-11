#include <bits/stdc++.h>

using namespace std;

int I = 1;
string alpha = "abcdefghijklmnopqrstuvwxyz";
map< string, int > id;

void generateWords(int len, int pos, string &word) {
    if (len == 1) {
        word += alpha[pos];
        id[word] = (I++);
        word.pop_back();
    }
    else {
        word += alpha[pos];
        for (int i = pos + 1; i <= 26 - len + 1; ++i) {
            generateWords(len - 1, i, word);
        }
        word.pop_back();
    }
}

void preprocess() {
    string word = "";
    int len = 1;
    while (len <= 5) {
        for (int i = 0; i <= 26 - len; ++i) {
            generateWords(len, i, word);
        }
        ++len;
    }
}

int main() {
    preprocess();
    string word;
    while (cin >> word) {
        cout << id[word] << endl;
    }
    return 0;
}

/*
Author: bumpy(-_-)
date: 12-Jan-2017
*/

