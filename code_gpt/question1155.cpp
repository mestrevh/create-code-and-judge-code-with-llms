/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int AA, BB;
    std::cin >> AA >> BB;

    std::string periodo;
    int horas12;

    if (AA == 0) {
        horas12 = 12;
        periodo = "am";
    } else if (AA == 12) {
        horas12 = 12;
        periodo = "pm";
    } else if (AA > 12) {
        horas12 = AA - 12;
        periodo = "pm";
    } else {
        horas12 = AA;
        periodo = "am";
    }

    std::cout << std::setw(2) << std::setfill('0') << horas12 << std::endl;
    std::cout << std::setw(2) << std::setfill('0') << BB << std::endl;
    std::cout << periodo << std::endl;

    return 0;
}
