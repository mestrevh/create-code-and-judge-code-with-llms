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

    int h, m;
    std::cin >> h >> m;

    std::string period;

    if (h < 12) {
        period = "am";
        if (h == 0) {
            h = 12;
        }
    } else {
        period = "pm";
        if (h > 12) {
            h -= 12;
        }
    }

    std::cout << std::setw(2) << std::setfill('0') << h << std::endl;
    std::cout << std::setw(2) << std::setfill('0') << m << std::endl;
    std::cout << period << std::endl;

    return 0;
}
