/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n1;
    std::cin >> n1;

    if (n1 < 1) {
        std::cout << "Erro - A lista deve ter pelo menos 1 elemento." << std::endl;
        return 0;
    }

    std::vector<int> lista_final;
    lista_final.reserve(n1);
    for (int i = 0; i < n1; ++i) {
        int valor;
        std::cin >> valor;
        lista_final.push_back(valor);
    }

    int n2;
    std::cin >> n2;

    if (n2 < 1) {
        std::cout << "Erro - A lista deve ter pelo menos 1 elemento." << std::endl;
        return 0;
    }

    lista_final.reserve(n1 + n2);
    for (int i = 0; i < n2; ++i) {
        int valor;
        std::cin >> valor;
        lista_final.push_back(valor);
    }

    for (size_t i = 0; i < lista_final.size(); ++i) {
        std::cout << lista_final[i] << (i == lista_final.size() - 1 ? "" : " ");
    }
    
    return 0;
}
