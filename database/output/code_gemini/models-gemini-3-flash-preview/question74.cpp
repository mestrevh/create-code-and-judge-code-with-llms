/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> numbers(100);
    for (int i = 0; i < 100; ++i) {
        if (!(std::cin >> numbers[i])) break;
    }

    int target;
    if (std::cin >> target) {
        for (int i = 0; i < 100; ++i) {
            if (numbers[i] == target) {
                std::cout << i << "\n";
            }
        }
    }

    return 0;
}