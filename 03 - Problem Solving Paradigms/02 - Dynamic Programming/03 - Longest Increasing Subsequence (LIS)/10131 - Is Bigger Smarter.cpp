#include <bits/stdc++.h>

using namespace std;

struct elephant {
    int weight, iq, index;
    bool operator > (const elephant &B) const{
        return iq > B.iq;
    }
};

elephant A[1010];

void printLIS(vector<int> &prev, int pos) {
    if (prev[pos] != -1) {
        printLIS(prev, prev[pos]);
    }
    printf("%d\n", A[pos].index);
}

int main() {
    int w, iq, n = 0;
    while (scanf("%d %d", &w, &iq) != EOF) {
        A[n].weight = w;
        A[n].iq = iq;
        A[n].index = n + 1;
        ++n;
    }
    vector<int> LIS(n);
    vector<int> prev(n);
    sort(A, A + n, greater<elephant> ());
    for (int i = 0; i < n; ++i) {
        int pre = -1, tmp = 0;
        for (int j = 0; j < i; ++j) {
            if (A[j].weight < A[i].weight && A[j].iq > A[i].iq && LIS[j] > tmp) {
                pre = j;
                tmp = LIS[j];
            }
        }
        LIS[i] = 1 + tmp;
        prev[i] = pre;
    }
    int pos = distance(LIS.begin(), max_element(LIS.begin(), LIS.end()));
    printf("%d\n", LIS[pos]);
    printLIS(prev, pos);
    return 0;
}

/*
Author: bumpy (-_-)
date: 3-Dec-2016
*/
