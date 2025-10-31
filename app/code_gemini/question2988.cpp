/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <cctype>
#include <algorithm>

struct Enemy {
    std::string name;
    int morale;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::queue<Enemy, std::list<Enemy>> enemies;
    std::string line;

    while (getline(std::cin, line) && line != "----------") {
        Enemy new_enemy;
        new_enemy.name = line;
        if (!getline(std::cin, line)) break;
        new_enemy.morale = std::stoi(line);
        enemies.push(new_enemy);
    }

    std::string speech_line;
    while (getline(std::cin, speech_line)) {
        if (enemies.empty()) {
            continue;
        }

        bool line_caused_flee;
        do {
            line_caused_flee = false;
            if (enemies.empty()) {
                break;
            }

            Enemy& current_enemy = enemies.front();
            bool fled = false;

            std::string lower_line = speech_line;
            std::transform(lower_line.begin(), lower_line.end(), lower_line.begin(),
                           [](unsigned char c){ return std::tolower(c); });

            std::string lower_name = current_enemy.name;
            std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(),
                           [](unsigned char c){ return std::tolower(c); });

            if (lower_line.find(lower_name) != std::string::npos) {
                fled = true;
            } else {
                int damage = 0;
                char initial_lower = lower_name[0];
                for (char c : lower_line) {
                    if (c == initial_lower) {
                        damage++;
                    }
                }
                current_enemy.morale -= damage;
                if (current_enemy.morale <= 0) {
                    fled = true;
                }
            }

            if (fled) {
                std::cout << "A horda de " << current_enemy.name << " fugiu\n";
                enemies.pop();
                line_caused_flee = true;
            }

        } while (line_caused_flee);
    }

    if (enemies.empty()) {
        std::cout << "Nao ha mais inimigos a vista\n";
    } else {
        std::cout << "Infelizmente o discurso nao foi tao intimidador assim.\n";
    }

    return 0;
}
