#include <bits/stdc++.h>

using namespace std;

int ca, cb, n;
bool flag[1001][1001];
vector< int > sol, res;

void solve(int a, int b) {
    if (flag[a][b]) return;
    if (b != n) {
        flag[a][b] = true;
        if (a < ca) { // fill A
            sol.push_back(0);
            solve(ca, b);
            sol.pop_back();
        }
        if (b < cb) { // fill B
            sol.push_back(1);
            solve(a, cb);
            sol.pop_back();
        }
        if (a > 0) { // empty A
            sol.push_back(2);
            solve(0, b);
            sol.pop_back();
        }
        if (b > 0) { // empty B
            sol.push_back(3);
            solve(a, 0);
            sol.pop_back();
        }
        if (a > 0 && b < cb) { // pour A B
            sol.push_back(4);
            if (a + b > cb)  solve(a - cb + b, cb);
            if (a + b <= cb) solve(0, a + b);
            sol.pop_back();
        }
        if (a < ca && b > 0) { // pour B A
            sol.push_back(5);
            if (a + b > ca)  solve(ca, b - ca + a);
            if (a + b <= ca) solve(a + b, 0);
            sol.pop_back();
        }
        flag[a][b] = false;
    }
    if (b == n) {
        if (res.empty() || sol.size() < res.size()) {
            res = sol;
        }
    }
}

int main() {
    while (scanf("%d %d %d", &ca, &cb, &n) != EOF) {
        res.clear();
        solve(0, 0);
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == 0) puts("fill A");
            if (res[i] == 1) puts("fill B");
            if (res[i] == 2) puts("empty A");
            if (res[i] == 3) puts("empty B");
            if (res[i] == 4) puts("pour A B");
            if (res[i] == 5) puts("pour B A");
        }
        puts("success");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 14-July-2018
*/
