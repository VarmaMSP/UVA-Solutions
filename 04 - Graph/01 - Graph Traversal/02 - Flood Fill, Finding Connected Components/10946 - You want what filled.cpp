#include <bits/stdc++.h>

using namespace std;

int m, n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char g[55][55];
vector< pair< int, char > > s;

bool compare(const pair< int, char >& a, const pair< int, char >&b) {
    if (a.first < b.first) return false;
    if (a.first > b.first) return true;
    return a.second < b.second;
}

int floodfill(int x, int y, char c) {
    if (x < 0 || x >= m || y < 0 || y >= n) return 0;
    if (g[x][y] != c) return 0;
    g[x][y] = '.';
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        int X = x + dx[i];
        int Y = y + dy[i];
        cnt += floodfill(X, Y, c);
    }
    return cnt;
}

int main() {
    int p = 1;
    while (scanf("%d %d", &m, &n) && (m|n)) {
        for (int i = 0; i < m; ++i) {
            scanf("%s", g[i]);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] != '.') {
                    char x = g[i][j];
                    s.push_back({floodfill(i, j, x), x});
                }
            }
        }
        sort(s.begin(), s.end(), compare);
        printf("Problem %d:\n", p++);
        for (auto const& x: s) {
            printf("%c %d\n", x.second, x.first);
        }
        s.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 18-Jul-2018
*/
