/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <string>

int romanToInt(const std::string& s) {
    std::unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int total = 0, prevValue = 0;
    
    for (char c : s) {
        int currentValue = romanMap[c];
        if (currentValue > prevValue) {
            total += currentValue - 2 * prevValue;
        } else {
            total += currentValue;
        }
        prevValue = currentValue;
    }
    
    return total;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    int number = romanToInt(input);
    
    if (number % 5 == 0) {
        std::cout << "O numero e multiplo de 5!" << std::endl;
    } else {
        std::cout << "O resto pela divisao por 5 do numero dado e igual a " << number % 5 << "!" << std::endl;
    }
    
    return 0;
}
