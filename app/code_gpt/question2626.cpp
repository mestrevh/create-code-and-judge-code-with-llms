/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<double> numbers;
    double num;

    while (iss >> num) {
        numbers.push_back(num);
    }

    for (double n : numbers) {
        std::cout << std::fixed << std::setprecision(3) << n << std::endl;
    }

    return 0;
}
