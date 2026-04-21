/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problema: Caio's Clash Cafe
 * Objetivo: Distribuir mesas (numeradas de B até E com passo K) entre F funcionários.
 * Regra: Cada funcionário recebe, por rodada, uma quantidade de mesas próxima a C.
 * A distribuição deve ser a mais igualitária possível dentro de cada rodada.
 */

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long B, E, K, C, F;
    // Leitura dos parâmetros de entrada
    if (!(cin >> B >> E >> K >> C >> F)) return 0;

    // Se o passo K for inválido, encerramos
    if (K == 0) return 0;

    // Cálculo do número total de mesas disponíveis (N)
    // Baseado nos exemplos, a mesa E está inclusa se for atingível pelo passo K.
    long long N = 0;
    if (E >= B) {
        N = (E - B) / K + 1;
    }

    // Iteramos por cada funcionário (ordenados de 0 a F-1)
    for (long long w = 0; w < F; ++w) {
        bool worked = false;
        // Para cada funcionário, simulamos as rodadas de distribuição
        for (long long r = 1; ; ++r) {
            // Sr define o índice global de início da mesa para esta rodada
            long long Sr = (r - 1) * F * C;
            
            // Se o índice de início da rodada ultrapassou o total de mesas, esta rodada não existe
            if (Sr >= N) break;

            // Tr é o total de mesas a serem distribuídas nesta rodada (máximo F * C)
            long long Tr = min(F * C, N - Sr);
            
            // k é a quantidade base de mesas para cada funcionário nesta rodada
            // rem é o resto da divisão, representando mesas extras para os primeiros funcionários
            long long k = Tr / F;
            long long rem = Tr % F;

            // Quantidade de mesas que o funcionário atual 'w' recebe nesta rodada
            long long num = k + (w < rem ? 1 : 0);
            
            // Se o funcionário não recebe mesas nesta rodada, ele não receberá em rodadas futuras
            if (num <= 0) break;

            worked = true;

            // Cálculo do índice inicial e final das mesas deste funcionário na rodada atual
            long long idx_start;
            if (w < rem) {
                idx_start = Sr + w * (k + 1);
            } else {
                idx_start = Sr + rem * (k + 1) + (w - rem) * k;
            }
            long long idx_end = idx_start + num - 1;

            // Formatação da saída conforme especificado
            cout << "distribution " << r << " to worker " << w << ": ";
            
            // Parte Q-P: Intervalo de trabalho (ID da mesa inicial - ID da mesa final)
            if (num > 1) {
                cout << B + idx_start * K << "-" << B + idx_end * K << ": ";
            } else {
                cout << B + idx_start * K << ": ";
            }

            // Listagem de todas as mesas individuais atendidas pelo funcionário nesta rodada
            for (long long i = 0; i < num; ++i) {
                cout << B + (idx_start + i) * K << ", ";
            }
            cout << "\n";
        }
        
        // Se um funcionário não trabalhou na primeira rodada, os próximos também não trabalharão
        if (!worked) break;
    }

    return 0;
}