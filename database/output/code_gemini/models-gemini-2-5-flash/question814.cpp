/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric> // Para std::iota

// Estrutura Disjoint Set Union (DSU) para verificar a conectividade
struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        // Inicializa cada elemento como seu próprio pai
        std::iota(parent.begin(), parent.end(), 0);
    }

    // Encontra o representante (raiz) do conjunto ao qual 'i' pertence
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Compressão de caminho: otimiza futuras buscas
        return parent[i] = find(parent[i]);
    }

    // Une os conjuntos aos quais 'i' e 'j' pertencem
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Une os dois conjuntos. Para este problema, a implementação simples é suficiente.
            parent[root_i] = root_j;
        }
    }
};

int main() {
    // Otimização padrão de I/O em C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int test_case_num = 1;

    // Loop para processar múltiplos conjuntos de teste.
    // O loop termina quando N for 0.
    while (std::cin >> N && N != 0) {
        std::cout << "Teste " << test_case_num << "\n";
        test_case_num++;

        std::vector<int> degrees(7, 0); // Armazena a contagem de vezes que cada valor (0-6) aparece
        DSU dsu(7);                    // Objeto DSU para verificar a conectividade dos valores
        std::vector<bool> is_present(7, false); // Marca se um valor (0-6) está presente em alguma peça

        // Processa as N peças de dominó para o conjunto de teste atual
        for (int i = 0; i < N; ++i) {
            int X, Y;
            std::cin >> X >> Y;
            degrees[X]++;
            degrees[Y]++;
            is_present[X] = true;
            is_present[Y] = true;
            dsu.unite(X, Y); // Une os valores X e Y no DSU, indicando que estão conectados
        }

        // Conta o número de valores com grau ímpar
        int odd_degree_count = 0;
        for (int i = 0; i < 7; ++i) {
            if (degrees[i] % 2 != 0) {
                odd_degree_count++;
            }
        }

        // Verifica a conectividade entre os valores que estão presentes nas peças
        int first_present_root = -1;
        bool connected_ok = true;
        for (int i = 0; i < 7; ++i) {
            if (is_present[i]) {
                if (first_present_root == -1) {
                    first_present_root = dsu.find(i); // Define a raiz do primeiro valor presente
                } else if (dsu.find(i) != first_present_root) {
                    connected_ok = false; // Se encontrarmos um valor presente com uma raiz diferente, não é conectado
                    break;
                }
            }
        }

        // Uma sequência válida de dominós (um caminho Euleriano) existe se:
        // 1. Todos os vértices com grau não zero estão na mesma componente conectada.
        // 2. Exatamente 0 ou 2 vértices têm grau ímpar.
        if ((odd_degree_count == 0 || odd_degree_count == 2) && connected_ok) {
            std::cout << "sim\n";
        } else {
            std::cout << "nao\n";
        }
        std::cout << "\n"; // Linha em branco após cada conjunto de teste
    }

    return 0;
}