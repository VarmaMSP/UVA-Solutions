#include <bits/stdc++.h>

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        while (n >= 10) {
            n = sum_of_digits(n);
        }
        printf("%d\n", n);
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 28-Jun-2018
*/
