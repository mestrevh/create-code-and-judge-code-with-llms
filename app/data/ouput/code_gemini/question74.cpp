/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    const int size = 100;
    int numbers[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }
    int last_number;
    std::cin >> last_number;
    for (int i = 0; i < size; ++i) {
        if (numbers[i] == last_number) {
            std::cout << i << "\n";
        }
    }
    return 0;
}
