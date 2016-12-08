#include <bits/stdc++.h>

using namespace std;

char G[105][105];
char tmp[105];
int m, n;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int floodfill (int x, int y, char c1, char c2) {
    if (x < 0 || y < 0 || x >= m || y >= n)
        return 0;
    if (G[x][y] != c1)
        return 0;
    G[x][y] = c2;
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        int X = x + dx[i];
        int Y = y + dy[i];
        cnt += floodfill(X, Y, c1, c2);
    }
    return cnt;
}

int main() {
    int tt, x, y;
    sscanf(gets(tmp), "%d", &tt);
    gets(tmp);
    while (tt--) {
        sscanf(gets(tmp), "%d %d", &x, &y);
        int i = 0;
        while (gets(G[i]) && G[i][0])
            ++i;
        m = i;
        n = strlen(G[0]);
        printf("%d\n", floodfill(x - 1, y - 1, '0', '1'));
        if (tt)
            printf("\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 8-Dec-2016
*/
