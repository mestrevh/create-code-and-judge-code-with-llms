/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::string dummy;
        while (std::cin >> dummy) {
        }
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    std::vector<bool> visited(n, false);
    long long total_coins = 0;
    int current_pos = 0;

    total_coins += coins[current_pos];
    visited[current_pos] = true;

    std::string move_command;
    while (std::cin >> move_command) {
        char direction = move_command[0];
        int steps = std::stoi(move_command.substr(1));

        if (direction == '+') {
            current_pos = (current_pos + steps) % n;
        } else {
            current_pos = ((current_pos - steps) % n + n) % n;
        }

        if (!visited[current_pos]) {
            total_coins += coins[current_pos];
            visited[current_pos] = true;
        }
    }

    std::cout << total_coins << std::endl;

    return 0;
}
