#include <bits/stdc++.h>

using namespace std;

int m, n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char grid[100][100];

int floodfill(int x, int y, char c1, char c2) {
    if (x < 0 || y < 0 || x >= m || y >= n)
        return 0;
    if (grid[x][y] != c1)
        return 0;
    grid[x][y] = c2;
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        int X = x + dx[i];
        int Y = y + dy[i];
        cnt += floodfill(X, Y, c1, c2);
    }
    return 1 + cnt;
}

bool compare(const pair< char, int > &a, const pair< char, int > &b) {
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main() {
    int tt, k = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d\n", &m, &n);
        for (int i = 0; i < m; ++i) {
            gets(grid[i]);
        }

        map< char, int > cnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '0') {
                    char tmp = grid[i][j];
                    floodfill(i, j, tmp, '0');
                    ++cnt[tmp];
                }
            }
        }

        vector< pair< char, int > > res(cnt.begin(), cnt.end());
        sort(res.begin(), res.end(), compare);

        printf("World #%d\n", k++);
        for (auto &z: res) {
            printf("%c: %d\n", z.first, z.second);
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 12-Dec-2016
*/
