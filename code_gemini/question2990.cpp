/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Adventure {
    std::string name;
    int doctor_regeneration;
    std::string location;
    std::string year;
    std::vector<std::string> friends;
    std::vector<std::string> enemies;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Adventure> all_adventures;
    std::string line;

    while (std::getline(std::cin, line) && line != "----------") {
        Adventure current_adventure;
        current_adventure.name = line;

        std::cin >> current_adventure.doctor_regeneration;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::getline(std::cin, current_adventure.location);
        std::getline(std::cin, current_adventure.year);

        std::getline(std::cin, line); 

        while (std::getline(std::cin, line) && line != "INIMIGOS") {
            current_adventure.friends.push_back(line);
        }

        while (std::getline(std::cin, line) && line != "FIM") {
            current_adventure.enemies.push_back(line);
        }

        all_adventures.push_back(current_adventure);
    }

    std::string search_tag, filter_tag, filter_value;

    while (std::getline(std::cin, search_tag)) {
        if (search_tag.empty()) {
            continue;
        }

        std::getline(std::cin, filter_tag);
        
        if (filter_tag != "TODOS") {
            std::getline(std::cin, filter_value);
        } else {
            filter_value.clear();
        }

        std::vector<std::string> results;

        for (const auto& adventure : all_adventures) {
            bool match = false;
            if (filter_tag == "TODOS") {
                match = true;
            } else if (filter_tag == "Aventura") {
                if (adventure.name == filter_value) match = true;
            } else if (filter_tag == "Doctor") {
                if (std::to_string(adventure.doctor_regeneration) == filter_value) match = true;
            } else if (filter_tag == "Local") {
                if (adventure.location == filter_value) match = true;
            } else if (filter_tag == "Ano") {
                if (adventure.year == filter_value) match = true;
            } else if (filter_tag == "Amigo") {
                for (const auto& friend_name : adventure.friends) {
                    if (friend_name == filter_value) {
                        match = true;
                        break;
                    }
                }
            } else if (filter_tag == "Inimigo") {
                for (const auto& enemy_name : adventure.enemies) {
                    if (enemy_name == filter_value) {
                        match = true;
                        break;
                    }
                }
            }

            if (match) {
                if (search_tag == "Aventura") {
                    results.push_back(adventure.name);
                } else if (search_tag == "Doctor") {
                    results.push_back(std::to_string(adventure.doctor_regeneration));
                } else if (search_tag == "Local") {
                    results.push_back(adventure.location);
                } else if (search_tag == "Ano") {
                    results.push_back(adventure.year);
                } else if (search_tag == "Amigo") {
                    for (const auto& friend_name : adventure.friends) {
                        results.push_back(friend_name);
                    }
                } else if (search_tag == "Inimigo") {
                    for (const auto& enemy_name : adventure.enemies) {
                        results.push_back(enemy_name);
                    }
                }
            }
        }

        if (results.empty()) {
            std::cout << "Nao foi possivel encontrar nada com esses parametros." << std::endl;
        } else {
            for (const auto& res : results) {
                std::cout << res << std::endl;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
