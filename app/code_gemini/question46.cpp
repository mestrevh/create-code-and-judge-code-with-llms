/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

long long to_days(int d, int m, int y) {
    if (m < 3) {
        y--;
        m += 12;
    }
    long long year_days = 365LL * y + y / 4 - y / 100 + y / 400;
    long long month_days = (153LL * m - 457) / 5;
    return year_days + month_days + d;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int d1, m1, y1;
    int d2, m2, y2;
    char slash;

    std::cin >> d1 >> slash >> m1 >> slash >> y1;
    std::cin >> d2 >> slash >> m2 >> slash >> y2;

    long long days1 = to_days(d1, m1, y1);
    long long days2 = to_days(d2, m2, y2);

    long long diff = days2 - days1;
    if (diff < 0) {
        diff = -diff;
    }

    std::cout << diff << std::endl;

    return 0;
}
