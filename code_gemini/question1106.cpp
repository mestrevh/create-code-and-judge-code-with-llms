/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

std::string to_upper(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return s;
}

void print_mesa(const std::string& nome_mesa, const std::vector<std::string>& convidados) {
    std::cout << nome_mesa << "\n";
    if (convidados.empty()) {
        std::cout << "VAZIA\n";
    } else {
        for (size_t i = 0; i < convidados.size(); ++i) {
            std::cout << i + 1 << " " << convidados[i] << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> mesa1;
    std::vector<std::string> mesa2;
    std::vector<std::string> mesa3;
    std::vector<std::string> mesa4;

    std::string nome, time_str;
    int idade;

    while (std::cin >> nome && nome != "-1") {
        std::cin >> idade >> time_str;

        std::string nome_upper = to_upper(nome);
        std::string time_upper = to_upper(time_str);

        if ((time_upper == "FLAMENGO" || time_upper == "SPORT" || time_upper == "VITORIA") && idade >= 30) {
            mesa1.push_back(nome_upper);
        } else if ((time_upper == "VASCO" || time_upper == "TREZE" || time_upper == "SANTOS") && (idade >= 18 && idade <= 36)) {
            mesa2.push_back(nome_upper);
        } else if ((time_upper == "BAHIA" || time_upper == "FORTALEZA" || time_upper == "GREMIO") && (idade >= 10 && idade < 18)) {
            mesa3.push_back(nome_upper);
        } else {
            mesa4.push_back(nome_upper);
        }
    }

    if (mesa1.empty() && mesa2.empty() && mesa3.empty() && mesa4.empty()) {
        std::cout << "JANTAR SEM CONVIDADOS\n";
    } else {
        print_mesa("MESA 1", mesa1);
        print_mesa("MESA 2", mesa2);
        print_mesa("MESA 3", mesa3);
        print_mesa("MESA 4", mesa4);
    }

    return 0;
}
