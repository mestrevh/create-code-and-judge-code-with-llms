/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::vector<int> roleta(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> roleta[i];
    }

    long long current_pos = 0;
    char command;
    int value;

    while (std::cin >> command && command != 'S') {
        std::cin >> value;

        if (command == 'D') {
            current_pos = (current_pos - (value % n) + n) % n;
        } else if (command == 'E') {
            current_pos = (current_pos + value) % n;
        }

        for (int i = 0; i < n; ++i) {
            long long print_index = (current_pos + i) % n;
            std::cout << roleta[print_index] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
