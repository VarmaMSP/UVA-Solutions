#include <bits/stdc++.h>
#define MAX 5000

using namespace std;

string fib[MAX + 50];

string add(string const& p, string const& q) {
    string res;
    int a, b, c = 0, d;
    int n = p.size() - 1;
    int m = q.size() - 1;
    while (n >= 0 || m >= 0) {
        a = n >= 0 ? p[n] - '0' : 0, n -= 1;
        b = m >= 0 ? q[m] - '0' : 0, m -= 1;
        d = a + b + c;
        c = d / 10;
        res.insert(0, 1, (char)((d % 10) + '0'));
    }
    if (c) res.insert(0, 1, (char)(c + '0'));
    return res;
}

void preprocess() {
    fib[0] = "0";
    fib[1] = "1";
    for (int i = 2; i <= MAX; ++i) {
        fib[i] = add(fib[i - 1], fib[i - 2]);
    }
}

int main() {
    preprocess();
    int n;
    while (cin >> n) {
        cout << "The Fibonacci number for " << n << " is " << fib[n] << endl;
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 9-Aug-2018
*/
