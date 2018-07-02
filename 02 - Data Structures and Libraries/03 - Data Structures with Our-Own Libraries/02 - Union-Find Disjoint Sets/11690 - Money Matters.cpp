#include <bits/stdc++.h>

using namespace std;

int p[10010];

int find_set(int x) {
  if (p[x] != x) {
      p[x] = find_set(p[x]);
  }
  return p[x];
}

int main() {
    int tt, n, m, a, b, owes[10010];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", owes + i);
            p[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &a, &b);
            int x = find_set(a);
            int y = find_set(b);
            if (x != y) {
                p[y] = x;
            }
        }
        map< int, int > group;
        for (int i = 0; i < n; ++i) {
            a = find_set(p[i]);
            group[a] += owes[i];
        }
        bool isPoss = true;
        for (auto const& x: group) {
            if (x.second != 0) {
                isPoss = false;
                break;
            }
        }
        puts(isPoss ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-July-2018
*/
