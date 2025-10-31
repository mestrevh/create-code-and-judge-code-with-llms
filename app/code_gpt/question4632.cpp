/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int i, num;
    std::cin >> i;
    std::vector<int> numbers;
    
    for (int j = 0; j < i; j++) {
        std::cin >> num;
        numbers.push_back(num);
    }

    int last = numbers.back();
    numbers.erase(std::remove(numbers.begin(), numbers.end(), last), numbers.end());

    std::cout << "[";
    for (size_t k = 0; k < numbers.size(); k++) {
        std::cout << numbers[k];
        if (k < numbers.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
