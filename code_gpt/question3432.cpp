/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    if (numbers.back() == 'x') {
        numbers.pop_back();
    }

    bool is_sorted = true;
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < numbers[i - 1]) {
            is_sorted = false;
            break;
        }
    }

    std::cout << (is_sorted ? "true" : "false") << std::endl;

    if (is_sorted) {
        double sum = 0;
        for (int number : numbers) {
            sum += number;
        }
        double average = sum / numbers.size();

        for (size_t i = 0; i < numbers.size(); ++i) {
            if (numbers[i] >= average) {
                std::cout << i << std::endl;
                break;
            }
        }
    }

    return 0;
}
