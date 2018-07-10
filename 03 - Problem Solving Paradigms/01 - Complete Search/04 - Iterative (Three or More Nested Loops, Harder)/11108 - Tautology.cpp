#include <bits/stdc++.h>

using namespace std;

bool apply(char op, bool a, bool b) {
    switch (op) {
        case 'K': return a && b;
        case 'A': return a || b;
        case 'C': return !a || b;
        case 'E': return a == b;
    }
}

bool value(char v, int p, int q, int r, int s, int t) {
    switch (v) {
        case 'p': return (bool)p;
        case 'q': return (bool)q;
        case 'r': return (bool)r;
        case 's': return (bool)s;
        case 't': return (bool)t;
    }
}

bool isOp(char x) {
    return x == 'K' || x == 'A' || x == 'N' || x == 'C' || x == 'E';
}

bool isVal(char x) {
    return x == 'p' || x == 'q' || x == 'r' || x == 's' || x == 't';
}

int main() {
    char str[110];
    while (scanf("%s", str) && str[0] != '0') {
        bool tau = true;
        for (int p = 0; p <= 1 && tau; ++p) for (int q = 0; q <= 1 && tau; ++q) {
            for (int r = 0; r <= 1 && tau; ++r) for (int s = 0; s <= 1 && tau; ++s) {
                for (int t = 0; t <= 1 && tau; ++t) {
                    int n = strlen(str);
                    stack< bool > stk;
                    for (int i = n - 1; i >= 0; --i) {
                        if (isVal(str[i])) {
                            stk.push(value(str[i], p, q, r, s, t));
                        }
                        if (isOp(str[i])) {
                            if (str[i] == 'N') {
                                bool a = stk.top(); stk.pop();
                                stk.push(!a);
                            } else {
                                bool a = stk.top(); stk.pop();
                                bool b = stk.top(); stk.pop();
                                stk.push(apply(str[i], a, b));
                            }
                        }
                    }
                    if (!stk.top()) tau = false;
                }
            }
        }
        puts(tau ? "tautology" : "not");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 10-July-2018
*/
