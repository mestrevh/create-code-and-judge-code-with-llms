/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

struct Convidado {
    std::string nome;
    int agregados;
    std::string comida;
    std::string bebida;
    std::string atracao;
};

std::string find_winner_string(const std::map<std::string, int>& votos) {
    if (votos.empty()) return "";
    auto winner_it = votos.begin();
    for (auto it = std::next(votos.begin()); it != votos.end(); ++it) {
        if (it->second > winner_it->second) {
            winner_it = it;
        }
    }
    return winner_it->first;
}

int find_winner_agregados(const std::map<int, int>& votos) {
    if (votos.empty()) return 0;
    auto winner_it = votos.begin();
    for (auto it = std::next(votos.begin()); it != votos.end(); ++it) {
        if (it->second > winner_it->second) {
            winner_it = it;
        }
    }
    return winner_it->first;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Convidado> convidados;
    std::map<int, int> votos_agregados;
    std::map<std::string, int> votos_comida;
    std::map<std::string, int> votos_bebida;
    std::map<std::string, int> votos_atracao;

    for (int i = 0; i < n; ++i) {
        Convidado c;
        std::cin >> c.nome >> c.agregados >> c.comida >> c.bebida;
        std::getline(std::cin >> std::ws, c.atracao);

        convidados.push_back(c);

        votos_agregados[c.agregados]++;
        votos_comida[c.comida]++;
        votos_bebida[c.bebida]++;
        votos_atracao[c.atracao]++;
    }

    int vencedor_agregados = find_winner_agregados(votos_agregados);
    std::string vencedor_comida = find_winner_string(votos_comida);
    std::string vencedor_bebida = find_winner_string(votos_bebida);
    std::string vencedor_atracao = find_winner_string(votos_atracao);

    std::cout << vencedor_agregados << "\n";
    std::cout << vencedor_comida << "\n";
    std::cout << vencedor_bebida << "\n";
    std::cout << vencedor_atracao << "\n";

    std::vector<std::string> vips;
    for (const auto& c : convidados) {
        int acertos = 0;
        if (c.agregados == vencedor_agregados) acertos++;
        if (c.comida == vencedor_comida) acertos++;
        if (c.bebida == vencedor_bebida) acertos++;
        if (c.atracao == vencedor_atracao) acertos++;

        if (acertos >= 2) {
            vips.push_back(c.nome);
        }
    }

    std::sort(vips.begin(), vips.end());

    std::cout << "convidados vip:\n";
    for (const auto& nome_vip : vips) {
        std::cout << nome_vip << "\n";
    }

    return 0;
}
