#include <bits/stdc++.h>

using namespace std;

bool compare(const string& a, const string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int n;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool visit[22][22];
string g[22], str;
set< string, bool(*)(const string&, const string&) > sol(&compare);

void solve(int x, int y) {
    if (str.size() > 2) {
        sol.insert(str);
    }
    for (int i = 0; i < 8; ++i) {
        int X = dx[i] + x;
        int Y = dy[i] + y;
        if (0 <= X && X < n && 0 <= Y && Y < n && !visit[X][Y] && g[x][y] < g[X][Y]) {
            str.push_back(g[X][Y]);
            visit[X][Y] = true;
            solve(X, Y);
            visit[X][Y] = false;
            str.pop_back();
        }
    }
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> g[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                str.push_back(g[i][j]);
                visit[i][j] = true;
                solve(i, j);
                visit[i][j] = false;
                str.pop_back();
            }
        }
        for (auto s: sol) cout << s << endl;
        if (tt) cout << endl;
        sol.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 24-July-2018
*/
