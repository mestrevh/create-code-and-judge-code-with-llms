/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cctype>
#include <tuple>

struct Carta {
    int ano;
    int mes;
    int dia;
    std::string data_original;
    std::string remetente;
    std::string destinatario;
};

std::string to_lower_str(const std::string& str) {
    std::string lower_str = "";
    for (char c : str) {
        lower_str += tolower(c);
    }
    return lower_str;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, int> meses_map = {
        {"janeiro", 1}, {"fevereiro", 2}, {"março", 3}, {"marco", 3},
        {"abril", 4}, {"maio", 5}, {"junho", 6},
        {"julho", 7}, {"agosto", 8}, {"setembro", 9},
        {"outubro", 10}, {"novembro", 11}, {"dezembro", 12}
    };

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    std::vector<Carta> cartas;
    cartas.reserve(n);

    for (int i = 0; i < n; ++i) {
        Carta c;
        std::getline(std::cin, c.data_original);
        std::getline(std::cin, c.remetente);
        std::getline(std::cin, c.destinatario);

        std::stringstream ss(c.data_original);
        std::string mes_str, de1, de2;
        ss >> c.dia >> de1 >> mes_str >> de2 >> c.ano;
        c.mes = meses_map[to_lower_str(mes_str)];
        
        cartas.push_back(c);
    }

    std::sort(cartas.begin(), cartas.end(), [](const Carta& a, const Carta& b) {
        if (std::tie(a.ano, a.mes, a.dia) != std::tie(b.ano, b.mes, b.dia)) {
            return std::tie(a.ano, a.mes, a.dia) < std::tie(b.ano, b.mes, b.dia);
        }
        
        std::string rem_a_lower = to_lower_str(a.remetente);
        std::string rem_b_lower = to_lower_str(b.remetente);
        if (rem_a_lower != rem_b_lower) {
            return rem_a_lower < rem_b_lower;
        }

        return to_lower_str(a.destinatario) < to_lower_str(b.destinatario);
    });

    for (const auto& c : cartas) {
        std::cout << c.data_original << "\n";
        std::cout << c.remetente << "\n";
        std::cout << c.destinatario << "\n";
    }

    return 0;
}
