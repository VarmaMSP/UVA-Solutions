#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        int sum = 0, res = 0;
        int money;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &money);
            sum += money;
            res = max(res, sum);
            if (sum < 0)
                sum = 0;
        }
        if (res > 0)
            printf("The maximum winning streak is %d.\n", res);
        else
            printf("Losing streak.\n");
    }
}

//Date: 30 Nov, 2016
//Author: bumpy -_-
