/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, D;
    std::cin >> N >> D;
    std::vector<int> numbers;

    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        if (num % 10 == D) {
            numbers.push_back(num);
        }
    }

    std::sort(numbers.rbegin(), numbers.rend());
    numbers.resize(std::min(5, static_cast<int>(numbers.size())));

    while (numbers.size() < 5) {
        numbers.push_back(-1);
    }

    std::sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
