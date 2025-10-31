/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> allied(4);
    std::vector<int> enemy(4);
    int reinforcement;

    for (int i = 0; i < 4; ++i) {
        std::cin >> allied[i];
    }

    for (int i = 0; i < 4; ++i) {
        std::cin >> enemy[i];
    }

    for (int i = 0; i < 4; ++i) {
        std::cin >> reinforcement;
        enemy[i] += reinforcement;
    }

    int allied_advantages = 0;
    int enemy_advantages = 0;

    for (int i = 0; i < 4; ++i) {
        if (allied[i] > enemy[i]) {
            allied_advantages++;
        } else if (enemy[i] > allied[i]) {
            enemy_advantages++;
        }
    }

    if (allied_advantages > 2) {
        std::cout << "Avancar\n";
    } else if (enemy_advantages > 2) {
        std::cout << "Recuar\n";
    } else {
        std::cout << "Permanecer\n";
    }

    return 0;
}
