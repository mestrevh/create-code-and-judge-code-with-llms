/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int volume, num_changes;

    do {
        std::cin >> volume >> num_changes;
    } while ((volume < 0 || volume > 100) || (num_changes < 0 || num_changes > 10));

    for (int i = 0; i < num_changes; ++i) {
        int change;
        std::cin >> change;
        volume += change;
        if (volume > 100) {
            volume = 100;
        }
        if (volume < 0) {
            volume = 0;
        }
    }

    std::cout << volume << std::endl;

    return 0;
}
