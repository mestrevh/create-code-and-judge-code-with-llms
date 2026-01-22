/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::vector<int> numbers;
        int num;
        while (iss >> num) {
            if (num == 420) {
                numbers.push_back(num);
                break;
            }
            numbers.push_back(num);
        }
        std::sort(numbers.begin(), numbers.end());
        std::cout << numbers.size() << std::endl;
        for (int i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << (i < numbers.size() - 1 ? " " : "");
        }
        std::cout << std::endl;
    }
    return 0;
}
