#include <bits/stdc++.h>

using namespace std;

typedef tuple< int, int, int > Ti3;

int l, r, c;
int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
int d[33][33][33];
char G[33][33][33];
bool visit[33][33][33];

int bfs(Ti3 s, Ti3 des) {
    queue< Ti3 > Q;
    int x = get<0>(s);
    int y = get<1>(s);
    int z = get<2>(s);
    d[x][y][z] = 0;
    visit[x][y][z] = true;
    Q.push(s);
    while (!Q.empty()) {
        Ti3 u = Q.front(); Q.pop();
        x = get<0>(u);
        y = get<1>(u);
        z = get<2>(u);
        if (u == des) {
            return d[x][y][z];
        }
        for (int i = 0; i < 6; ++i) {
            int X = x + dx[i];
            int Y = y + dy[i];
            int Z = z + dz[i];
            if (0 <= X && X < r && 0 <= Y && Y < c && 0 <= Z && Z < l && !visit[X][Y][Z] && G[X][Y][Z] != '#') {
                visit[X][Y][Z] = true;
                d[X][Y][Z] = d[x][y][z] + 1;
                Q.push({X, Y, Z});
            }
        }
    }
    return -1;
}

int main() {
    Ti3 src, des;
    while (cin >> l >> r >> c && (l|r|c)) {
        for (int z = 0; z < l; ++z) {
            for (int x = 0; x < r; ++x) {
                for (int y = 0; y < c; ++y) {
                    cin >> G[x][y][z];
                    if (G[x][y][z] == 'S') src = {x, y, z};
                    if (G[x][y][z] == 'E') des = {x, y, z};
                }
            }
        }
        int time = bfs(src, des);
        if (time >= 0)  cout << "Escaped in " << time << " minute(s)." << endl;
        if (time == -1) cout << "Trapped!" << endl;
        memset(visit, false, sizeof(visit));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 27-July-2018
*/
