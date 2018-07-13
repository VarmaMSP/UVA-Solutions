#include <bits/stdc++.h>

using namespace std;

int n;
string rule, pass, word[110];
char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


void gen(int p) {
    if (p < rule.size()) {
        if (rule[p] == '#') {
            for (int i = 0; i < n; ++i) {
                int tmp = pass.size();
                pass.append(word[i]);
                gen(p + 1);
                pass.resize(tmp);
            }
        }
        if (rule[p] == '0') {
            for (int i = 0; i < 10; ++i) {
                int tmp = pass.size();
                pass.push_back(digit[i]);
                gen(p + 1);
                pass.resize(tmp);
            }
        }
        return ;
    }
    cout << pass << endl;
}

int main() {
    int m;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> word[i];
        }
        cin >> m;
        cout << "--" << endl;
        while (m--) {
            cin >> rule;
            gen(0);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 13-July-2018
*/
