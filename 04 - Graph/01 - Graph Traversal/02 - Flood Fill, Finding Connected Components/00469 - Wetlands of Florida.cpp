#include <bits/stdc++.h>

using namespace std;

int m, n, id[100][100], s[5000];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
string g[100];

int fill(int x, int y, int w) {
    if (x < 0 || x >= m || y < 0 || y >= n) return 0;
    if (g[x][y] != 'W') return 0;
    g[x][y] = 'L', id[x][y] = w;
    int res = 1;
    for (int i = 0; i < 8; ++i) {
        int X = x + dx[i];
        int Y = y + dy[i];
        res += fill(X, Y, w);
    }
    return res;
}

int main() {
    int tt, p, q;
    string line;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        m = 0;
        cin.ignore();
        while (getline(cin, line) && (line[0] == 'W' || line[0] == 'L')) {
            g[m++] = line;
        }
        n = g[0].size();
        int w = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 'W') {
                    s[w] = fill(i, j, w);
                    w += 1;
                }
            }
        }
        stringstream sin;
        do {
            sin << line;
            sin >> p >> q;
            sin.clear();
            cout << s[id[p - 1][q - 1]] << endl;
        } while (getline(sin, line) && !line.empty());
        if (tt) {
            cout << endl;
        }
    }
    return 0;
}

/*
date: 18-Jul-2018
*/
