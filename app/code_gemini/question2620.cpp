/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::string> nomes(n);
    std::vector<int> quantidades(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> nomes[i] >> quantidades[i];
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        std::string nome_retirar;
        int quantidade_retirar;
        std::cin >> nome_retirar >> quantidade_retirar;

        for (int j = 0; j < n; ++j) {
            if (nomes[j] == nome_retirar) {
                if (quantidades[j] >= quantidade_retirar) {
                    quantidades[j] -= quantidade_retirar;
                    std::cout << "Tem " << quantidades[j] << " " << nomes[j] << " no estoque\n";
                } else {
                    std::cout << "Nao tem " << nomes[j] << " suficiente no estoque\n";
                }
                break;
            }
        }
    }

    return 0;
}
