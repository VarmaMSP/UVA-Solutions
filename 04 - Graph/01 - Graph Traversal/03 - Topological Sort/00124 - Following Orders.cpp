#include <bits/stdc++.h>

using namespace std;

vector<int> G[26];
bool node[26], visit[26];
int inDeg[26], nodeCnt, res[26];

inline void decInDeg(int i) {
    for (auto j: G[i]) {
        --inDeg[j];
    }
}

inline void incInDeg(int i) {
    for (auto j: G[i]) {
        ++inDeg[j];
    }
}

void printSort(int id) {
    if (id == nodeCnt) { // solution found
        for (int i = 0; i < nodeCnt; ++i) {
            printf("%c", 'a' + res[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < 26; ++i) if(node[i] && !visit[i]) {
            if (inDeg[i] == 0) {
                res[id] = i;
                visit[i] = true;
                decInDeg(i);
                printSort(id + 1);
                incInDeg(i);
                visit[i] = false;
            }
        }
    }
}

int main() {
    bool firstInput = true;
    string str;
    char u, v;
    while (getline(cin, str)) {
        istringstream nodes(str);
        int i = 0;
        nodeCnt = 0;
        while (nodes >> u) {
            node[u - 'a'] = true;
            nodeCnt++;
        }
        getline(cin, str);
        istringstream edges(str);
        while (edges >> u >> v) {
            G[u - 'a'].push_back(v - 'a');
            ++inDeg[v - 'a'];
        }

        printf(firstInput ? "" : "\n");
        firstInput = false;
        printSort(0);

        for(int i = 0; i < 26; ++i)
            G[i].clear();
        memset(node, false, sizeof(node));
        memset(inDeg, 0, sizeof(inDeg));
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 26-Jul-2016
*/
