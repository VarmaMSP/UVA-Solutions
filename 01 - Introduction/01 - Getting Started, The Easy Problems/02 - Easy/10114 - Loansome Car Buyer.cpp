#include<bits/stdc++.h>

int main() {
    int duration, m, n;
    double loan, downpayment, dep[101];
    while (scanf("%d %lf %lf %d", &duration, &downpayment, &loan, &n) && duration > 0) {
        while (n--) {
            double tmp;
            scanf("%d %lf", &m, &tmp);
            for (int i = m; i <= duration; ++i) dep[i] = tmp;
        }
        int time = 0;
        double monthly_payment = loan / duration;
        double car_value = (loan + downpayment) * (1 - dep[0]);
        while (car_value < loan) {
            time += 1;
            loan -= monthly_payment;
            car_value -= car_value * dep[time];
        }
        printf("%d month", time);
        printf(time != 1 ? "s\n" : "\n");
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
