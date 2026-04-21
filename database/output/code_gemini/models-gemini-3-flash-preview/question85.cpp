/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problema: Adivinhe (Estilo Mastermind)
 * Objetivo: Calcular acertos "Excelente" (E) e "Bom" (B).
 * E: Mesmo caractere na mesma posição.
 * B: Mesmo caractere em posição diferente, sem repetição de contagem.
 * Complexidade: O(K * G * N), onde K é o número de jogos, G o número de chutes e N o tamanho da senha.
 */

int main() {
    // Otimização de I/O para C++ competitivo
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k_games;
    // Lê o número total de jogos
    if (!(cin >> k_games)) return 0;

    while (k_games--) {
        int n_size;
        // Lê o tamanho da senha do jogo atual
        if (!(cin >> n_size)) break;

        string secret;
        // Lê a senha secreta
        if (!(cin >> secret)) break;

        string guess;
        // Lê os chutes sucessivos até o fim do jogo
        while (cin >> guess) {
            // Condição de saída: N caracteres '0' representam a desistência do jogador
            bool all_zeros = true;
            for (int i = 0; i < n_size && i < (int)guess.length(); ++i) {
                if (guess[i] != '0') {
                    all_zeros = false;
                    break;
                }
            }
            if (all_zeros) break;

            int excellent = 0;
            int good = 0;
            int s_freq[10] = {0}; // Frequência dos caracteres restantes na senha
            int g_freq[10] = {0}; // Frequência dos caracteres restantes no chute

            // Primeira passada: Identificar acertos excelentes (E)
            for (int i = 0; i < n_size; ++i) {
                if (secret[i] == guess[i]) {
                    excellent++;
                } else {
                    // Contabiliza frequências apenas para caracteres que não foram excelentes
                    s_freq[secret[i] - '0']++;
                    g_freq[guess[i] - '0']++;
                }
            }

            // Segunda passada: Identificar acertos bons (B) nos caracteres restantes
            // O alfabeto permitido é de dígitos de 1 a 7
            for (int i = 1; i <= 7; ++i) {
                good += min(s_freq[i], g_freq[i]);
            }

            // Formatação da saída exigida: (E,B)
            cout << "(" << excellent << "," << good << ")\n";

            // Se o chute for igual à senha, o jogo atual termina
            if (guess == secret) break;
        }
    }

    return 0;
}