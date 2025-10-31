/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const std::vector<std::string> meses = {
        "", "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    int n;
    std::cin >> n;

    std::map<std::pair<int, int>, std::vector<std::string>> aniversarios;

    for (int i = 0; i < n; ++i) {
        std::string nome;
        int dia, mes;
        std::cin >> nome >> dia >> mes;
        aniversarios[{mes, dia}].push_back(nome);
    }

    bool encontrou_aniversario_compartilhado = false;

    for (const auto& par : aniversarios) {
        if (par.second.size() > 1) {
            encontrou_aniversario_compartilhado = true;
            
            int mes = par.first.first;
            int dia = par.first.second;

            std::cout << "Dia " << dia << " de " << meses[mes] << ": ";

            for (size_t i = 0; i < par.second.size(); ++i) {
                std::cout << par.second[i];
                if (i < par.second.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "\n";
        }
    }

    if (!encontrou_aniversario_compartilhado) {
        std::cout << "Ninguem faz aniversario no mesmo dia\n";
    }

    return 0;
}
