/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    input = input.substr(1, input.length() - 2); // Remove colchetes
    std::stringstream ss(input);
    std::string token;
    std::vector<int> values;

    while (std::getline(ss, token, ',')) {
        values.push_back(std::stoi(token));
    }

    int maior = *std::max_element(values.begin(), values.end());
    int menor = *std::min_element(values.begin(), values.end());
    double media = 0.0;

    if (!values.empty()) {
        for (int num : values) {
            media += num;
        }
        media /= values.size();
    }

    std::cout << "Maior: " << maior << std::endl;
    std::cout << "Menor: " << menor << std::endl;
    std::cout << "Media: " << std::fixed << std::setprecision(2) << media << std::endl;

    return 0;
}
