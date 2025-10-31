/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int d, m, y;
    std::cin >> d >> m >> y;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m < 1 || m > 12 || d < 1 || d > days_in_month[m]) {
        std::cout << "Data invalida" << std::endl;
        return 0;
    }

    d++;
    if (d > days_in_month[m]) {
        d = 1;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }

    std::cout << d << "." << m << "." << y << std::endl;

    return 0;
}
