/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para std::binary_search

// Armazenamento global para potências pré-computadas das bases de hash.
// precomputed_powers[k_idx][j] irá armazenar (B[k_idx]^j) % M.
// O tamanho máximo da string é 100, então precisamos de potências de B^0 até B^99.
// Um vetor de tamanho 100 é suficiente para os índices de 0 a 99.
std::vector<std::vector<long long>> precomputed_powers;

// Função para calcular um único valor de hash para uma string S usando potências pré-computadas.
// H[i](S[0 .. L-1]) = (S[0]*B[i]^0 + S[1]*B[i]^1 + ... + S[L-1]*B[i]^(L-1)) mod M
long long calculate_hash(const std::string& s, int k_idx, long long m) {
    long long hash_val = 0;
    // Itera sobre a string, aplicando as potências pré-computadas.
    for (int j = 0; j < s.length(); ++j) {
        // (long long)s[j] garante que o valor ASCII do caractere seja tratado como um número.
        // precomputed_powers[k_idx][j] contém (B[k_idx]^j) % M.
        hash_val = (hash_val + (long long)s[j] * precomputed_powers[k_idx][j]) % m;
    }
    return hash_val;
}

int main() {
    // Otimiza as streams de I/O padrão do C++ para programação competitiva.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    // Armazena os usuários registrados para busca binária (detecção de verdadeiros positivos).
    std::vector<std::string> registered_users(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> registered_users[i];
    }

    long long M; // Tamanho do vetor de bits V do Filtro de Bloom.
    int K;       // Quantidade de funções de hash.
    std::cin >> M >> K;

    std::vector<long long> B(K); // Bases para as funções de hash H[0], ..., H[K-1].
    for (int i = 0; i < K; ++i) {
        std::cin >> B[i];
    }

    // Pré-computa as potências de cada base B[k] módulo M até o comprimento máximo da string (100).
    precomputed_powers.resize(K, std::vector<long long>(100)); // Tamanho 100 para índices de 0 a 99.
    for (int k = 0; k < K; ++k) {
        precomputed_powers[k][0] = 1; // B^0 = 1
        for (int j = 1; j < 100; ++j) { // Potências até B^99 são necessárias para strings de comprimento até 100.
            precomputed_powers[k][j] = (precomputed_powers[k][j-1] * B[k]) % M;
        }
    }

    // Vetor de bits do Filtro de Bloom, inicialmente todos falsos (0).
    // std::vector<bool> é uma especialização que usa bits para eficiência de memória.
    std::vector<bool> bloom_filter(M, false);

    // Adiciona strings ao Filtro de Bloom.
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < K; ++k) {
            long long hash_index = calculate_hash(registered_users[i], k, M);
            bloom_filter[hash_index] = true;
        }
    }

    int Q; // Número de consultas.
    std::cin >> Q;

    for (int i = 0; i < Q; ++i) {
        std::string query_s;
        std::cin >> query_s;

        bool bloom_says_present = true;
        for (int k = 0; k < K; ++k) {
            long long hash_index = calculate_hash(query_s, k, M);
            if (!bloom_filter[hash_index]) {
                bloom_says_present = false;
                break; // Se qualquer bit for 0, a string definitivamente não está no conjunto.
            }
        }

        if (!bloom_says_present) {
            // Caso 0: Filtro de Bloom diz que não está presente.
            std::cout << 0 << "\n";
        } else {
            // Filtro de Bloom diz que está presente. Agora verifica se é um verdadeiro positivo ou falso positivo.
            // Como registered_users está ordenado lexicograficamente, usa std::binary_search.
            bool actually_registered = std::binary_search(registered_users.begin(), registered_users.end(), query_s);
            if (actually_registered) {
                // Caso 2: A string foi de fato registrada.
                std::cout << 2 << "\n";
            } else {
                // Caso 1: Falso positivo.
                std::cout << 1 << "\n";
            }
        }
    }

    return 0;
}