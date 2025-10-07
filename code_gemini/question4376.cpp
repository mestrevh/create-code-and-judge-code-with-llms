/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int base_width = 2 * n;
    for (int i = 1; i <= n; ++i) {
        int num_x = 2 * i;
        int num_spaces = (base_width - num_x) / 2;
        for (int j = 0; j < num_spaces; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < num_x; ++j) {
            std::cout << "X";
        }
        std::cout << "\n";
    }
    int trunk_height = n / 2;
    int trunk_spaces = (base_width - 2) / 2;
    for (int i = 0; i < trunk_height; ++i) {
        for (int j = 0; j < trunk_spaces; ++j) {
            std::cout << " ";
        }
        std::cout << "XX\n";
    }
    return 0;
}
