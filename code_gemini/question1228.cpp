/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    for (char &c : line) {
        if (c == '[' || c == ']' || c == ',') {
            c = ' ';
        }
    }

    std::stringstream ss(line);
    int number;
    double sum_of_odds = 0.0;
    int count_of_odds = 0;

    while (ss >> number) {
        if (number % 2 != 0) {
            sum_of_odds += number;
            count_of_odds++;
        }
    }

    if (count_of_odds > 0) {
        double average = sum_of_odds / count_of_odds;
        std::cout << std::fixed << std::setprecision(2) << average << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(2) << 0.0 << std::endl;
    }

    return 0;
}
