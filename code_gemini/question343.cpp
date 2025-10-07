/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    std::map<char, int> roman_values = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int number = 0;
    if (!s.empty()) {
        number = roman_values[s.back()];
        for (int i = s.length() - 2; i >= 0; --i) {
            if (roman_values[s[i]] < roman_values[s[i + 1]]) {
                number -= roman_values[s[i]];
            } else {
                number += roman_values[s[i]];
            }
        }
    }

    int remainder = number % 5;

    if (remainder == 0) {
        std::cout << "O numero e multiplo de 5!\n";
    } else {
        std::cout << "O resto pela divisao por 5 do numero dado e igual a " << remainder << "!\n";
    }

    return 0;
}
