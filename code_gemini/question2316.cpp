/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

long long produzir(int indice, int N, const std::vector<std::string>& nomes, long long X, long long K, long long& total_produzido) {
    long long minha_producao_total = 0;

    // Base Case: Leaf node (no subordinates)
    if (2 * indice + 1 >= N) {
        if (total_produzido < K) {
            minha_producao_total = X;
            total_produzido += X;
        }
    } 
    // Recursive Step: Internal node
    else {
        long long prod_sub1 = 0;
        long long prod_sub2 = 0;

        // Call first subordinate
        prod_sub1 = produzir(2 * indice + 1, N, nomes, X, K, total_produzido);

        // Check if second subordinate exists and if we still need more production
        if (2 * indice + 2 < N) {
            if (total_produzido < K) {
                prod_sub2 = produzir(2 * indice + 2, N, nomes, X, K, total_produzido);
            }
        }
        
        minha_producao_total = 2 * (prod_sub1 + prod_sub2);
    }

    std::string chefe;
    if (indice == 0) {
        chefe = "Nairobi";
    } else {
        chefe = nomes[(indice - 1) / 2];
    }
    std::cout << "Estou dando " << minha_producao_total << " euros a " << chefe << "\n";

    return minha_producao_total;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::string> nomes(N);
    if (N > 0) {
        for (int i = 0; i < N; ++i) {
            std::cin >> nomes[i];
        }
    }

    long long X, K;
    std::cin >> X >> K;

    long long total_produzido = 0;

    if (N > 0) {
        produzir(0, N, nomes, X, K, total_produzido);
    }
    
    if (total_produzido >= K) {
        std::cout << "Bom trabalho\n";
    } else {
        std::cout << "Precisamos acelerar o processo\n";
    }

    return 0;
}
