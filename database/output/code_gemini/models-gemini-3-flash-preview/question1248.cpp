/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

// Array bidimensional global para suportar restrições de memória e uso obrigatório.
// Coordenadas variam de 1 a 1000, então 1005x1005 é seguro.
// Representação: 0 = verde (excelente), 1 = amarelo (danificado), 2 = vermelho (danificado e infestado).
static int grid[1005][1005];

int main() {
    // Otimização de I/O para lidar com volumes de dados de até 10^6.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    long long red_count = 0;

    // Leitura da matriz e identificação das áreas infestadas.
    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= C; ++j) {
            string color;
            cin >> color;
            if (color == "verde") {
                grid[i][j] = 0;
            } else if (color == "amarelo") {
                grid[i][j] = 1;
            } else if (color == "vermelho") {
                grid[i][j] = 2;
                red_count++;
            }
        }
    }

    // O repelente de lesmas é aplicado primeiro em todas as áreas infestadas.
    // Custo: 3 Galeões por área. Efeito: vermelho torna-se amarelo.
    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (grid[i][j] == 2) {
                grid[i][j] = 1;
            }
        }
    }

    // Leitura da quantidade de áreas atingidas pelo feitiço Trivialus.
    int S;
    if (cin >> S) {
        for (int k = 0; k < S; ++k) {
            int x, y;
            cin >> x >> y;
            // O feitiço recupera áreas danificadas (amarelo) tornando-as excelentes (verde).
            // Se já for excelente, o feitiço não tem efeito.
            if (x >= 1 && x <= L && y >= 1 && y <= C) {
                if (grid[x][y] == 1) {
                    grid[x][y] = 0;
                }
            }
        }
    }

    // Cálculo final de áreas excelentes para a colheita.
    long long final_green_count = 0;
    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (grid[i][j] == 0) {
                final_green_count++;
            }
        }
    }

    // Hagrid ganha 4 Galeões por área excelente cultivada e gasta 3 por infestada inicial.
    long long total_income = final_green_count * 4;
    long long total_cost = red_count * 3;
    long long final_profit = total_income - total_cost;

    // Saída dos resultados conforme formato especificado.
    if (final_profit < 0) {
        cout << "prejuizo" << endl;
    } else {
        cout << final_profit << endl;
    }

    return 0;
}