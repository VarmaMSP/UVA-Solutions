#include <bits/stdc++.h>

using namespace std;

int main() {
    int tt, k = 1, n;
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d", &n);
        vector<int> h(n), w(n), LIS(n), LDS(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &h[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w[i]);
        }
        for (int i = 0; i < n; ++i) {
            int tmpLIS = 0;
            int tmpLDS = 0;
            for (int j = 0; j < n; ++j) {
                if (h[j] < h[i] && LIS[j] > tmpLIS) {
                    tmpLIS = LIS[j];
                }
                if (h[j] > h[i] && LDS[j] > tmpLDS) {
                    tmpLDS = LDS[j];
                }
            }
            LIS[i] = w[i] + tmpLIS;
            LDS[i] = w[i] + tmpLDS;
        }
        int inc = *max_element(LIS.begin(), LIS.end());
        int dec = *max_element(LDS.begin(), LDS.end());
        if (inc >= dec)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", k++, inc, dec);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", k++, dec, inc);
    }
    return 0;
}
