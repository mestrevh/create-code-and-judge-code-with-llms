/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string comparators;
    std::getline(std::cin, comparators);
    std::vector<int> numbers;
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    std::sort(numbers.begin(), numbers.end());

    std::vector<int> result;
    int n = comparators.size();
    int left = 0, right = n;

    for (char c : comparators) {
        if (c == '<') {
            result.push_back(numbers[left++]);
        } else {
            result.push_back(numbers[right--]);
        }
    }
    result.push_back(numbers[left]);

    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << " " << comparators[i] << " ";
    }
    std::cout << result[n] << std::endl;

    return 0;
}
