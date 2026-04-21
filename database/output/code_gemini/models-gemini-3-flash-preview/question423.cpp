/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Grande Mestre em Programação Competitiva
 * Solução: Jogo do Bicho
 * Complexidade: O(T), onde T é o número de casos de teste.
 * Espaço: O(1)
 */

/**
 * Função para determinar o grupo do animal baseado nos dois últimos dígitos.
 * Os grupos são divididos em blocos de 4, de 01-04 até 97-00.
 * O número 00 pertence ao grupo 25, junto com 97, 98 e 99.
 */
int get_group(int n) {
    int last2 = n % 100;
    // O grupo 25 contém 97, 98, 99 e 00
    if (last2 == 0) return 25;
    // Para 01-99, a fórmula (X-1)/4 + 1 mapeia corretamente para 1-25
    return (last2 - 1) / 4 + 1;
}

int main() {
    // Otimização de I/O padrão C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double v;
    int n, m;

    // Loop principal: Lê o valor da aposta, o número escolhido e o número sorteado
    while (cin >> v >> n >> m) {
        // Condição de parada: V = M = N = 0
        if (v == 0 && n == 0 && m == 0) break;

        // Extração dos sufixos para as regras de premiação
        int n4 = n % 10000;
        int m4 = m % 10000;
        int n3 = n % 1000;
        int m3 = m % 1000;
        int n2 = n % 100;
        int m2 = m % 100;

        double prize = 0.0;

        // Aplicação das regras de premiação em ordem de prioridade (maior prêmio primeiro)
        
        // 1. Mesmos quatro últimos dígitos (milhar, centena, dezena e unidade)
        if (n4 == m4) {
            prize = v * 3000.0;
        }
        // 2. Mesmos três últimos dígitos (centena, dezena e unidade)
        else if (n3 == m3) {
            prize = v * 500.0;
        }
        // 3. Mesmos dois últimos dígitos (dezena e unidade)
        else if (n2 == m2) {
            prize = v * 50.0;
        }
        // 4. Dois últimos dígitos no mesmo grupo (mesmo animal)
        else if (get_group(n) == get_group(m)) {
            prize = v * 16.0;
        }
        // 5. Nenhum dos casos acima
        else {
            prize = 0.0;
        }

        // Saída formatada com duas casas decimais
        cout << fixed << setprecision(2) << prize << "\n";
    }

    return 0;
}