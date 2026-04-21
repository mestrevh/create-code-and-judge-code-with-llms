/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>

using namespace std;

bool is_leap(long long y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    int d, m;
    long long y, n;
    
    if (scanf("%d/%d/%lld", &d, &m, &y) != 3) return 0;
    if (scanf("%lld", &n) != 1) return 0;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (n >= 146097) {
        y += (n / 146097) * 400;
        n %= 146097;
    } else if (n <= -146097) {
        long long cycles = (-n) / 146097;
        y -= cycles * 400;
        n = -((-n) % 146097);
    }

    if (n > 0) {
        while (n > 0) {
            int dim = (m == 2 && is_leap(y)) ? 29 : days_in_month[m];
            if (n >= (long long)(dim - d + 1)) {
                n -= (long long)(dim - d + 1);
                d = 1;
                m++;
                if (m > 12) {
                    m = 1;
                    y++;
                }
            } else {
                d += (int)n;
                n = 0;
            }
        }
    } else if (n < 0) {
        n = -n;
        while (n > 0) {
            if (n >= (long long)d) {
                n -= (long long)d;
                m--;
                if (m < 1) {
                    m = 12;
                    y--;
                }
                int dim = (m == 2 && is_leap(y)) ? 29 : days_in_month[m];
                d = dim;
            } else {
                d -= (int)n;
                n = 0;
            }
        }
    }

    printf("%02d/%02d/%04lld\n", d, m, y);

    return 0;
}