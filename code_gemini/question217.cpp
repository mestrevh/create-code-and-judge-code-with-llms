/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int max_sequencia = 1;
    int contagem_atual = 1;
    
    int valor_anterior;
    std::cin >> valor_anterior;
    
    for (int i = 1; i < n; ++i) {
        int valor_atual;
        std::cin >> valor_atual;
        if (valor_atual == valor_anterior) {
            contagem_atual++;
        } else {
            max_sequencia = std::max(max_sequencia, contagem_atual);
            contagem_atual = 1;
        }
        valor_anterior = valor_atual;
    }
    
    max_sequencia = std::max(max_sequencia, contagem_atual);
    
    std::cout << max_sequencia << std::endl;
    
    return 0;
}
