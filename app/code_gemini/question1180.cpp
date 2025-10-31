/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int h24, m;
    std::cin >> h24 >> m;

    int h12;
    std::string period;

    if (h24 == 0) {
        h12 = 12;
        period = "am";
    } else if (h24 < 12) {
        h12 = h24;
        period = "am";
    } else if (h24 == 12) {
        h12 = 12;
        period = "pm";
    } else {
        h12 = h24 - 12;
        period = "pm";
    }

    std::cout << std::setfill('0') << std::setw(2) << h12 << std::endl;
    std::cout << std::setfill('0') << std::setw(2) << m << std::endl;
    std::cout << period << std::endl;

    return 0;
}
