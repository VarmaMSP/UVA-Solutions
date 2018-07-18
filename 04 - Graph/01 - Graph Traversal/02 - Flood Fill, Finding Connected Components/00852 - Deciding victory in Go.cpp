#include <bits/stdc++.h>

char b[11][11];
bool visit[11][11];

int border(int x, int y) {
    if (x < 0 || x >= 9 || y < 0 || y >= 9 || visit[x][y]) return 0;
    if (b[x][y] == 'O') return 1 << 0;
    if (b[x][y] == 'X') return 1 << 1;
    visit[x][y] = true;
    return border(x - 1, y) | border(x, y + 1) | border(x + 1, y) | border(x, y - 1);
}

void floodfill(int x, int y, char c) {
    if (x < 0 || x >= 9 || y < 0 || y >= 9) return;
    if (b[x][y] != '.') return;
    b[x][y] = c;
    floodfill(x - 1, y, c);
    floodfill(x, y + 1, c);
    floodfill(x + 1, y, c);
    floodfill(x, y - 1, c);
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        for (int i = 0; i < 9; ++i) {
            scanf("%s", b[i]);
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (b[i][j] == '.') {
                    int bor = border(i, j);
                    if (bor == 1) floodfill(i, j, 'O');
                    if (bor == 2) floodfill(i, j, 'X');
                }
            }
        }
        int white = 0, black = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (b[i][j] == 'X') black += 1;
                if (b[i][j] == 'O') white += 1;
            }
        }
        printf("Black %d White %d\n", black, white);
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 18-Jul-2018
*/
