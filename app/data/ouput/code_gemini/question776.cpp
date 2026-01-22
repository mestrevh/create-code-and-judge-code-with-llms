/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int get_period(int year, std::string era) {
    if (era == "aC") {
        if (year >= 4000) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if (year <= 476) {
            return 2;
        } else if (year <= 1789) {
            return 3;
        } else {
            return 4;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int max_p = 0;
    for (int i = 0; i < 3; ++i) {
        int year;
        std::string era;
        std::cin >> year >> era;
        max_p = std::max(max_p, get_period(year, era));
    }

    std::cout << max_p << std::endl;

    return 0;
}
