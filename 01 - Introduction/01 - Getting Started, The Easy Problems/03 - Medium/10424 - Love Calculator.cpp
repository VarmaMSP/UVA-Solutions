#include <bits/stdc++.h>

using namespace std;

int sum(int a) {
    if (a / 10 > 0) {
        int s = 0;
        while (a) {
            s += a % 10;
            a /= 10;
        }
        return sum(s);
    }
    return a;
}

int score(string s) {
    double res = 0;
    for (auto c: s)  {
        if ('A' <= c && c <= 'Z') res += c - 'A' + 1;
        if ('a' <= c && c <= 'z') res += c - 'a' + 1;
    }
    return sum(res);
}

int main() {
    string a, b;
    while (getline(cin, a)) {
        getline(cin, b);
        double x = score(a);
        double y = score(b);
        if (x > y) {
            swap(x, y);
        }
        printf("%.2lf", 100.0 * (x / y));
        puts(" %");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 17-Aug-2018
*/
