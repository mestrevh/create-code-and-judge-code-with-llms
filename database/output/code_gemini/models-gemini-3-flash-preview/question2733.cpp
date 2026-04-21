/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

/**
 * Função que conta a ocorrência de um inteiro x em um vetor v.
 * @param v Referência constante para o vetor de inteiros.
 * @param x O valor inteiro a ser buscado.
 * @return O número de vezes que x aparece em v.
 */
int contar_ocorrencias(const std::vector<int>& v, int x) {
    int contador = 0;
    for (int item : v) {
        if (item == x) {
            contador++;
        }
    }
    return contador;
}

int main() {
    // Otimização de I/O para padrões de programação competitiva
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, n;
    
    // Leitura do valor buscado e do tamanho do vetor
    if (!(std::cin >> x >> n)) {
        return 0;
    }

    // Alocação do vetor e leitura dos n itens
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    // Chamada da função e exibição do resultado
    std::cout << contar_ocorrencias(v, x) << "\n";

    return 0;
}