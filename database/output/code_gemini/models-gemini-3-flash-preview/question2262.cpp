/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problema: Treinamento Uchiha
 * Objetivo: Calcular a pontuação de Sasuke e Itachi no arremesso de kunais em um alvo 
 * com pontuação crescente até o centro e decrescente até as extremidades.
 * Complexidade: O(N + I)
 * Onde N é o tamanho do alvo e I é a quantidade de kunais arremessadas por cada um.
 */

int main() {
    // Otimização de I/O para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, I;
    // Leitura do tamanho do alvo e da quantidade de kunais por participante
    if (!(cin >> N >> I)) return 0;

    // Conforme as regras, o uso de array (vector) é obrigatório para representar o alvo.
    // A pontuação em cada posição i (1-indexed) é min(i, N - i + 1).
    vector<long long> target(N + 1);
    for (long long i = 1; i <= N; ++i) {
        target[i] = min(i, N - i + 1);
    }

    // Processamento da pontuação do Sasuke
    long long s_score = 0;
    // Uso de array booleano para garantir que a mesma casa de pontuação não seja contada duas vezes.
    // O mesmo Uchiha não pode acertar a mesma posição duas vezes.
    vector<bool> s_hit(N + 1, false);
    for (long long i = 0; i < I; ++i) {
        long long p;
        cin >> p;
        // Se o arremesso for para fora do alvo (p < 1 ou p > N), a kunai não conta.
        if (p >= 1 && p <= N) {
            if (!s_hit[p]) {
                s_score += target[p];
                s_hit[p] = true;
            }
        }
    }

    // Processamento da pontuação do Itachi
    long long i_score = 0;
    vector<bool> i_hit(N + 1, false);
    for (long long i = 0; i < I; ++i) {
        long long p;
        cin >> p;
        if (p >= 1 && p <= N) {
            if (!i_hit[p]) {
                i_score += target[p];
                i_hit[p] = true;
            }
        }
    }

    // Saída Formatada: Pontuações individuais
    cout << "Sasuke: " << s_score << "\n";
    cout << "Itachi: " << i_score << "\n";

    // Lógica para determinar o vencedor e os insultos específicos
    if (s_score > i_score) {
        cout << "Sasuke Uchiha" << "\n";
        // Se Itachi não pontuou, Sasuke o insulta
        if (i_score == 0) {
            cout << "Um genjutsu desse nivel nao funciona em mim" << "\n";
        }
    } else if (i_score > s_score) {
        cout << "Itachi Uchiha" << "\n";
        // Se Sasuke não pontuou, Itachi o insulta
        if (s_score == 0) {
            cout << "Voce e fraco, lhe falta odio" << "\n";
        }
    } else {
        // Caso de empate (s_score == i_score)
        if (s_score == 0) {
            // Caso especial: ninguém pontuou
            cout << "Os Uchihas nem sao tao bons mesmo" << "\n";
        } else {
            // Empate com pontuação positiva
            cout << "O empate nunca existiu, voce esta preso num genjutsu" << "\n";
        }
    }

    return 0;
}