/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

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
    std::vector<int> numbers;
    int num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    if (!numbers.empty()) {
        std::cout << *std::max_element(numbers.begin(), numbers.end()) << std::endl;
    }

    return 0;
}
