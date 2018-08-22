#include <bits/stdc++.h>

using namespace std;

bool isOpen(char t) {
    return t == '(' || t == '[' || t == '{' || t == '<' || t == 'A';
}

bool isClose(char t) {
    return t == ')' || t == ']' || t == '}' || t == '>' || t == 'B';
}

bool match(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    if (a == '<' && b == '>') return true;
    if (a == 'A' && b == 'B') return true;
    return false;
}

int main() {
    char str[3050];
    while (gets(str)) {
        stack< char > S;
        int cnt = 0, len = strlen(str);
        bool isBalanced = true;
        for (int i = 0; i < len; ++i, ++cnt) {
            char tmp = str[i];
            if (i + 1 < len) {
                if (tmp == '(' && str[i + 1] == '*') tmp = 'A', i += 1;
                if (tmp == '*' && str[i + 1] == ')') tmp = 'B', i += 1;
            }
            if (isOpen(tmp)) S.push(tmp);
            if (isClose(tmp)) {
                if (!S.empty() && match(S.top(), tmp)) {
                    S.pop();
                } else {
                    isBalanced = false;
                    break;
                }
            }
        }
        if (!S.empty()) isBalanced = false;
        if (isBalanced) {
            printf("YES\n");
        } else {
            printf("NO %d\n", cnt + 1);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 7-Dec-2016
*/
