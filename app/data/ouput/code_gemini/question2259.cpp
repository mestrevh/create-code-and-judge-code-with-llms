/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Ninja {
    std::string nome;
    int chakra;
    int jutsus;
    int potencial;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::getline(std::cin, s);

    bool invertido = (s == "Esse naruto...");

    int n;
    std::cin >> n;
    
    if (n == 0) {
        std::cout << "\n";
        std::cout << "Esse semestre ninguem veio treinar na aldeia da folha\n";
        return 0;
    }

    std::vector<Ninja> ninjas(n);
    std::vector<int> jutsus_temp(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> ninjas[i].nome >> ninjas[i].chakra >> jutsus_temp[i];
    }

    for (int i = 0; i < n; ++i) {
        if (invertido) {
            ninjas[i].jutsus = jutsus_temp[n - 1 - i];
        } else {
            ninjas[i].jutsus = jutsus_temp[i];
        }
        ninjas[i].potencial = ninjas[i].chakra - ninjas[i].jutsus;
    }

    std::sort(ninjas.begin(), ninjas.end(), [](const Ninja& a, const Ninja& b) {
        return a.potencial > b.potencial;
    });

    int classificados = 0;
    for (const auto& ninja : ninjas) {
        if (ninja.potencial > 0) {
            std::cout << ninja.nome << " esta classificado(a)\n";
            classificados++;
        } else {
            std::cout << ninja.nome << " esta desclassificado(a)\n";
        }
    }

    std::cout << "\n";

    if (classificados > 0) {
        std::cout << "Kakashi tera um total de " << classificados << " aluno(s) nesse semestre\n";
    } else {
        std::cout << "Esse semestre ninguem veio treinar na aldeia da folha\n";
    }

    return 0;
}
