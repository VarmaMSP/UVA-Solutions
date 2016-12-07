#include <bits/stdc++.h>

using namespace std;

char G[110][110];
bool visit[110][110];
int dx[] = {1, -1, 0,  0};
int dy[] = {0,  0, 1, -1};
int n;

void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n || G[r][c] == '.' || visit[r][c])
        return;
    visit[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        int x = r + dx[i];
        int y = c + dy[i];
        floodfill(x, y);
    }
}

int main(){
    int tt, k = 1;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", &G[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (G[i][j] == 'x' && !visit[i][j]) {
                    floodfill(i, j);
                    ++res;
                }
            }
        }
        printf("Case %d: %d\n", k++, res);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                visit[i][j] = false;
            }
        }
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 26-Jul-2016
*/
