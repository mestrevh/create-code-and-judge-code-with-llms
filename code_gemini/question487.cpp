/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int previous_number;
    int current_number;
    bool is_ordered = true;

    if (!(std::cin >> previous_number) || previous_number == 0) {
        std::cout << "EM ORDEM\n";
        return 0;
    }

    while (std::cin >> current_number && current_number != 0) {
        if (current_number <= previous_number) {
            is_ordered = false;
        }
        previous_number = current_number;
    }

    if (is_ordered) {
        std::cout << "EM ORDEM\n";
    } else {
        std::cout << "FORA DE ORDEM\n";
    }

    return 0;
}
