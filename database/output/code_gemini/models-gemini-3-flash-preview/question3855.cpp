/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Grande Mestre em Programação Competitiva.
 * Solução para o problema "Os registradores de Kammera Man".
 * Complexidade de Tempo: O(N), onde N é o número de instruções.
 * Complexidade de Espaço: O(1).
 */

int read4() {
    int val = 0, bit;
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> bit)) return -1;
        val = (val << 1) | bit;
    }
    return val;
}

int main() {
    // Otimização de I/O padrão Maratona
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // O registrador de 8 bits é lido inicialmente como dois blocos de 4 bits
    int h = read4();
    if (h == -1) return 0;
    int l = read4();
    if (l == -1) return 0;

    // O programa roda enquanto a instrução for diferente de 15 (1111)
    while (h != 15) {
        if (h == 0) {
            // Instrução 0: Lê um novo valor de 4 bits para a parte baixa
            l = read4();
            if (l == -1) break;
        } else if (h == 2) {
            // Instrução 2: Mostra os valores de High e Low em decimal
            cout << "O registrador tem os seguintes valores:\n";
            cout << "High: " << h << "\n";
            cout << "Low: " << l << "\n";
        } else if (h == 5) {
            // Instrução 5: Mostra o valor armazenado ao quadrado em decimal
            cout << l * l << "\n";
        } else if (h == 8) {
            // Instrução 8: Mostra o valor em hexadecimal maiúsculo
            cout << hex << uppercase << l << dec << nouppercase << "\n";
        } else if (h == 12) {
            // Instrução 12: Lê um inteiro decimal e multiplica pelo valor armazenado
            int multi;
            if (!(cin >> multi)) break;
            cout << multi * l << "\n";
        } else {
            // Caso a instrução não seja nenhuma das mapeadas
            cout << "ERRO: A instrucao nao existe.\n";
        }

        // Lê a próxima instrução de 4 bits
        h = read4();
        if (h == -1) break;
    }

    return 0;
}