/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> numbers;
    int number;
    double sum = 0;

    while (iss >> number) {
        numbers.push_back(number);
        sum += number;
    }

    double average = numbers.empty() ? 0 : sum / numbers.size();
    std::cout << "Media = " << std::fixed << std::setprecision(1) << average << std::endl;

    return 0;
}
