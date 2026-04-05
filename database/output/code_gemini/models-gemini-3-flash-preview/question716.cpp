/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * Persona: Grande Mestre em Programação Competitiva e especialista em C++ moderno.
 * Problema: BOING (Bingo com pesos de ranking).
 * Complexidade de Tempo: O(C * (N log N + P * K)), onde C é o número de casos.
 * Complexidade de Espaço: O(N) para o armazenamento das bolas e tabela hash.
 */

// Tamanho da tabela hash para mapeamento de valor da bola para o seu ranking.
// Como N <= 50.000, uma potência de 2 como 2^17 (131.072) oferece um load factor baixo (~0.38).
const int HASH_SIZE = 1 << 17;
int table_key[HASH_SIZE];
int table_val[HASH_SIZE];

/**
 * Insere um valor de bola e seu ranking na tabela hash usando endereçamento aberto
 * e sondagem linear. O uso de Knuth's Multiplicative Hash ajuda a distribuir chaves.
 */
inline void insert_hash(int k, int v) {
    unsigned int h = ((unsigned int)k * 0x9E3779B1U) & (HASH_SIZE - 1);
    while (table_key[h] != -1) {
        h = (h + 1) & (HASH_SIZE - 1);
    }
    table_key[h] = k;
    table_val[h] = v;
}

/**
 * Consulta o ranking de um valor sorteado.
 * Assume-se que o valor sempre existe na tabela conforme as regras do problema.
 */
inline int query_hash(int k) {
    unsigned int h = ((unsigned int)k * 0x9E3779B1U) & (HASH_SIZE - 1);
    while (table_key[h] != k) {
        h = (h + 1) & (HASH_SIZE - 1);
    }
    return table_val[h];
}

int main() {
    // Otimização padrão de I/O para C++.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, P;
    long long A;
    int caseNum = 0;

    // Leitura contínua dos casos de teste.
    while (cin >> N >> M >> K >> P >> A) {
        // Leitura e ordenação dos valores das bolas na urna para determinar os rankings.
        vector<int> balls(N);
        for (int i = 0; i < N; ++i) {
            cin >> balls[i];
        }
        sort(balls.begin(), balls.end());

        // Limpeza e preenchimento da tabela hash com os rankings.
        memset(table_key, -1, sizeof(table_key));
        for (int i = 0; i < N; ++i) {
            insert_hash(balls[i], i);
        }

        cout << "caso " << caseNum++ << ":";

        // Cálculo da pontuação máxima possível para evitar cálculos desnecessários.
        long long max_possible_score = (long long)K * (N - 1);

        if (A > max_possible_score) {
            // Se o alvo A for maior que o máximo possível, ninguém vence.
            // Consome os dados de entrada de sorteios para manter o fluxo.
            for (long long i = 0; i < (long long)P * K; ++i) {
                int dummy;
                cin >> dummy;
            }
        } else {
            // Processamento dos sorteios de cada um dos P jogadores.
            for (int i = 0; i < P; ++i) {
                long long current_score = 0;
                bool possible = true;
                for (int j = 0; j < K; ++j) {
                    int draw;
                    cin >> draw;
                    if (possible) {
                        // O ranking é obtido em O(1) via hash table.
                        current_score += query_hash(draw);
                        // Se a pontuação já exceder A, o jogador não pode mais vencer.
                        if (current_score > A) possible = false;
                    }
                }
                // Verifica se o jogador fez BOING.
                if (possible && current_score == A) {
                    cout << " " << i;
                }
            }
        }

        // Formatação de saída conforme especificado: uma linha em branco após cada caso.
        cout << "\n\n";
    }

    return 0;
}