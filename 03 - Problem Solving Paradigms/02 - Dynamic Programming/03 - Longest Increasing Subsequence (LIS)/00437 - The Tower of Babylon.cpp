#include <bits/stdc++.h>

using namespace std;

struct block {
    int x, y, z;

    block(int a, int b, int c):
        x(a), y(b), z(c) {}

    bool operator < (const block &B) const {
        return x*y < B.x * B.y;
    }
};

int height[110];
vector < block > A;

int main() {
    int n, x, y, z, c = 1;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            A.push_back(block(max(x, y), min(x, y), z));
            A.push_back(block(max(y, z), min(y, z), x));
            A.push_back(block(max(z, x), min(z, x), y));
        }
        sort(A.begin(), A.end());
        for (int i = 0; i < 3*n; ++i) {
            int temp = 0;
            for (int j = 0; j < i; ++j) {
                if (A[j].x < A[i].x && A[j].y < A[i].y && height[j] > temp) {
                    temp = height[j];
                }
            }
            height[i] = A[i].z + temp;
        }
        printf("Case %d: maximum height = %d\n", c++, *max_element(height, height + 3*n));
        A.clear();
    }
    return 0;
}

/*
Author : bumpy (-_-)
date : 4-Dec-2016
*/
