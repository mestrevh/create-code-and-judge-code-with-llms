/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

struct Pokemon {
    std::string nome;
    std::string tipo;
    int ataque;
    int defesa;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Pokemon> pokedex;
    pokedex.reserve(n);
    for (int i = 0; i < n; ++i) {
        Pokemon p;
        std::cin >> p.nome >> p.tipo >> p.ataque >> p.defesa;
        pokedex.push_back(p);
    }

    std::string command;
    while (std::cin >> command && command != "0") {
        if (command == "list") {
            std::string type_to_list;
            std::cin >> type_to_list;
            int count = 1;
            for (const auto& p : pokedex) {
                if (p.tipo == type_to_list) {
                    std::cout << "Pokemon " << count << ": " << p.nome << "\n";
                    std::cout << " Ataque: " << p.ataque << "\n";
                    std::cout << " Defesa: " << p.defesa << "\n";
                    count++;
                }
            }
        } else if (command == "luta") {
            std::string p1_name, vs, p2_name;
            std::cin >> p1_name >> vs >> p2_name;

            Pokemon p1, p2;
            bool p1_found = false;
            bool p2_found = false;
            
            for (const auto& p : pokedex) {
                if (!p1_found && p.nome == p1_name) {
                    p1 = p;
                    p1_found = true;
                }
                if (!p2_found && p.nome == p2_name) {
                    p2 = p;
                    p2_found = true;
                }
                if (p1_found && p2_found) {
                    break;
                }
            }
            
            int diff1 = p1.ataque - p2.defesa;
            int diff2 = p2.ataque - p1.defesa;

            if (diff1 > diff2) {
                std::cout << p1.nome << " deitou " << p2.nome << " na porrada\n";
            } else if (diff2 > diff1) {
                std::cout << p2.nome << " deitou " << p1.nome << " na porrada\n";
            } else {
                std::cout << "parece que temos um empate\n";
            }
        }
    }

    return 0;
}
