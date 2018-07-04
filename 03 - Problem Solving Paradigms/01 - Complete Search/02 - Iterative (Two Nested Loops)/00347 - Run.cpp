#include <bits/stdc++.h>

bool res[9876544];

void dfs(int *G, bool *visit, int u) {
    if (!visit[G[u]]) {
        visit[G[u]] = true;
        dfs(G, visit, G[u]);
    }
}

bool isRound(int n) {
    int G[11];
    int d = ceil(log10(n));
    bool visit[11] = { false };
    for (int i = d - 1; i >= 0; --i) {
        G[i] = (i + (n % 10)) % d;
        n /= 10;
    }
    dfs(G, visit, 0);
    for (int i = 0; i < d; ++i) {
        if (!visit[i]) return false;
    }
    return true;
}

int isValid(int n) {
    bool mark[10] = { false };
    while (n) {
        if (mark[n % 10] || n % 10 == 0) return false;
        mark[n % 10] = true;
        n /= 10;
    }
    return true;
}

int main() {
  for (int x = 12; x <= 9876543; ++x) {
      res[x] = isValid(x) && isRound(x);
  }
  int n, i = 1;
  while (scanf("%d", &n) && n) {
      while (!res[n]) ++n;
      printf("Case %d: %d\n", i++, n);
  }
  return 0;
}

/*
Author: bumpy (-_-)
date: 4-July-2018
*/
