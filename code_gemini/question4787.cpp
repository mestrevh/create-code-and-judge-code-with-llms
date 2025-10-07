/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

struct Pokemon {
    std::string nome;
    std::string tipo;
    int poder;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Pokemon> pokemons;
    std::string nome_in, tipo_in;
    int poder_in;

    while (std::cin >> nome_in >> tipo_in >> poder_in) {
        pokemons.push_back({nome_in, tipo_in, poder_in});
    }

    if (pokemons.empty()) {
        return 0;
    }

    int poder_resultante = 0;
    size_t max_name_len = 0;
    std::map<std::string, int> type_counts;
    
    for (const auto& p : pokemons) {
        poder_resultante += p.poder;
        if (p.nome.length() > max_name_len) {
            max_name_len = p.nome.length();
        }
        type_counts[p.tipo]++;
    }

    int max_freq = 0;
    for(const auto& pair : type_counts) {
        if (pair.second > max_freq) {
            max_freq = pair.second;
        }
    }
    
    std::string tipo_resultante;
    std::vector<std::string> precedence = {"fogo", "agua", "planta", "eletrico", "dragao"};
    for (const auto& t : precedence) {
        if (type_counts.count(t) && type_counts[t] == max_freq) {
            tipo_resultante = t;
            break;
        }
    }
    
    std::string nome_resultante = "";
    int indice_global = 0;

    for (const auto& p : pokemons) {
        double fracao_poder = 0.0;
        if (poder_resultante > 0) {
            fracao_poder = static_cast<double>(p.poder) / poder_resultante;
        }
        int contribuicao = std::max(1, static_cast<int>(std::floor(fracao_poder * max_name_len)));

        for (int i = 0; i < contribuicao; ++i) {
            int indice_copia = indice_global + i;
            if (static_cast<size_t>(indice_copia) >= p.nome.length()) {
                nome_resultante += p.nome.back();
            } else {
                nome_resultante += p.nome[indice_copia];
            }
        }
        indice_global += contribuicao;
    }

    std::cout << "Nome: " << nome_resultante << "\n";
    std::cout << "Tipo: " << tipo_resultante << "\n";
    std::cout << "Poder: " << poder_resultante << "\n";

    return 0;
}
