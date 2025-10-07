/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

int main() {
    double num;
    std::cin >> num;

    std::ostringstream oss;

    oss << std::fixed << std::setprecision(2) << num;
    std::cout << "|" << oss.str() << "|\n";

    oss.str("");
    oss << std::fixed << std::setprecision(5) << num;
    std::cout << "|" << oss.str() << "|\n";

    oss.str("");
    oss << std::fixed << std::setprecision(1) << num;
    std::cout << "|      " << oss.str() << "|\n";

    oss.str("");
    oss << std::fixed << std::setprecision(1) << num;
    std::cout << "|" << oss.str() << "      |\n";

    return 0;
}
