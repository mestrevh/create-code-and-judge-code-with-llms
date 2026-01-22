/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> carrinhos;
    int n;

    while (std::cin >> n && n != -1) {
        carrinhos.push_back(n);
    }

    int k;
    std::cin >> k;

    int posicao_encontrada = -1;
    for (int i = 0; i < carrinhos.size(); ++i) {
        if (carrinhos[i] == k) {
            posicao_encontrada = i + 1;
            break;
        }
    }

    if (posicao_encontrada != -1) {
        std::cout << "O bilhete sorteado e o " << k << " e esta no carrinho " << posicao_encontrada << std::endl;
    } else {
        std::cout << "Nenhum carrinho foi sorteado" << std::endl;
    }

    return 0;
}
