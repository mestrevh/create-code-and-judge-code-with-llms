/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numbers(3);
    if (!(std::cin >> numbers[0] >> numbers[1] >> numbers[2])) {
        return 0;
    }

    std::sort(numbers.begin(), numbers.end());

    std::cout << numbers[0] << "\n" << numbers[1] << "\n" << numbers[2] << "\n";

    return 0;
}