/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int max_pos = 0;
    std::vector<int> obstacles_input(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> obstacles_input[i];
        if (obstacles_input[i] > max_pos) {
            max_pos = obstacles_input[i];
        }
    }

    std::vector<bool> is_obstacle(max_pos + 1, false);
    for (int pos : obstacles_input) {
        is_obstacle[pos] = true;
    }

    for (int f = 1; ; ++f) {
        bool collision_found = false;
        for (int jump_pos = f; jump_pos <= max_pos; jump_pos += f) {
            if (is_obstacle[jump_pos]) {
                collision_found = true;
                break;
            }
        }
        if (!collision_found) {
            std::cout << f << '\n';
            break;
        }
    }

    return 0;
}
