#include <bits/stdc++.h>

using namespace std;

map< char, char > bracketMatch;

void init() {
    bracketMatch['('] = ')';
    bracketMatch['['] = ']';
    bracketMatch['{'] = '}';
    bracketMatch['<'] = '>';
    bracketMatch['A'] = 'B'; //(* *)
}

inline bool isValidOpenBracket(char t) {
    return  t == '(' || t == '[' || t == '{' ||
            t == '<' || t == 'A';
}

inline bool isValidClosedBracket(char t) {
    return  t == ')' || t == ']' || t == '}' ||
            t == '>' || t == 'B';
}

int main() {
    init();
    char str[3050];
    while (gets(str)) {
        stack< char > S;
        int len = strlen(str);
        int pos = -1;
        int cnt = 0;
        bool isBalanced = true;
        for (int i = 0; i < len; ++i, ++cnt) {
            char tmp = str[i];
            if (i < len - 1 && tmp == '(' && str[i + 1] == '*') {
                tmp = 'A'; // (*
                i += 1;
            }
            if (i < len - 1 && tmp == '*' && str[i + 1] == ')') {
                tmp = 'B'; // *)
                i += 1;
            }
            if (isValidOpenBracket(tmp)) {
                S.push(tmp);
            }
            else if (isValidClosedBracket(tmp)) {
                if (!S.empty() && bracketMatch[S.top()] == tmp) {
                    S.pop();
                } else {
                    isBalanced = false;
                    break;
                }
            }
        }
        if (isBalanced && !S.empty()) {
            isBalanced = false;
        }
        if (isBalanced)
            printf("YES\n");
        else
            printf("NO %d\n", cnt + 1);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 7-Dec-2016
*/
