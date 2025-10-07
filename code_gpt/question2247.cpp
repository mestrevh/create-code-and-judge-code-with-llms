/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    int d1, m1, a1, d2, m2, a2;
    std::cin >> d1 >> m1 >> a1;
    std::cin >> d2 >> m2 >> a2;

    std::tm start = {};
    start.tm_mday = d1;
    start.tm_mon = m1 - 1;
    start.tm_year = a1 - 1900;

    std::tm end = {};
    end.tm_mday = d2;
    end.tm_mon = m2 - 1;
    end.tm_year = a2 - 1900;

    std::time_t start_time = std::mktime(&start);
    std::time_t end_time = std::mktime(&end);

    double seconds = std::difftime(end_time, start_time);
    int days = seconds / (60 * 60 * 24);

    std::cout << days << std::endl;

    return 0;
}
