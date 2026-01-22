/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <cctype>

struct Enemy {
    std::string name;
    int morale;
};

int main() {
    std::list<Enemy> enemies;
    std::string line;

    while (std::getline(std::cin, line) && line != "----------") {
        Enemy enemy;
        enemy.name = line;
        std::getline(std::cin, line);
        enemy.morale = std::stoi(line);
        enemies.push_back(enemy);
    }

    while (std::getline(std::cin, line)) {
        if (enemies.empty()) break;
        
        Enemy &current = enemies.front();
        bool escaped = false;

        if (line.find(current.name) != std::string::npos) {
            escaped = true;
        } else {
            for (char c : line) {
                if (std::tolower(c) == std::tolower(current.name[0])) {
                    current.morale--;
                }
            }
            
            if (current.morale <= 0) {
                escaped = true;
            }
        }
        
        if (escaped) {
            std::cout << "A horda de " << current.name << " fugiu\n";
            enemies.pop_front();
        }
    }

    if (enemies.empty()) {
        std::cout << "Nao ha mais inimigos a vista.\n";
    } else {
        std::cout << "Infelizmente o discurso nao foi tao intimidador assim.\n";
    }

    return 0;
}
