/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problema: Maior submatriz de 1s.
 * Complexidade: O(T * N^3) onde N <= 25.
 * Estratégia: Processar cada linha como a base de um histograma e encontrar o maior retângulo.
 */

int main() {
    // Otimização de I/O padrão para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Lendo o número de casos de teste
    if (!(cin >> T)) return 0;
    
    string line;
    // Consumir o restante da linha onde o inteiro T foi lido
    getline(cin, line);

    for (int t = 0; t < T; ++t) {
        vector<string> mat;
        // Lendo a matriz. Ignoramos linhas em branco iniciais e paramos na primeira linha em branco após o início da matriz.
        while (getline(cin, line)) {
            // Limpar caracteres de controle e espaços no final da linha
            while (!line.empty() && (line.back() == '\r' || line.back() == '\n' || line.back() == ' ' || line.back() == '\t')) {
                line.pop_back();
            }
            
            if (line.empty()) {
                if (mat.empty()) continue; // Ignora linhas em branco antes da matriz começar
                else break; // Uma linha em branco após o início da matriz sinaliza o fim dela
            }
            mat.push_back(line);
        }

        // Se não conseguimos ler nenhuma matriz, interrompemos
        if (mat.empty()) break;

        int rows = (int)mat.size();
        int cols = 0;
        // Determinar o número máximo de colunas (caso as linhas tenham comprimentos variados)
        for (int i = 0; i < rows; ++i) {
            if ((int)mat[i].size() > cols) {
                cols = (int)mat[i].size();
            }
        }

        int maxArea = 0;
        // 'h' armazena a altura de 1s consecutivos terminando na linha atual para cada coluna
        vector<int> h(cols, 0);

        for (int i = 0; i < rows; ++i) {
            int currentRowLen = (int)mat[i].size();
            for (int j = 0; j < cols; ++j) {
                // Se o caractere é '1', incrementamos a altura; caso contrário, zeramos
                if (j < currentRowLen && mat[i][j] == '1') {
                    h[j]++;
                } else {
                    h[j] = 0;
                }
            }

            // Para cada linha, calculamos o maior retângulo no histograma formado por 'h'
            // Dada a restrição N <= 25, O(N^2) no histograma é aceitável (Total O(N^3))
            for (int j = 0; j < cols; ++j) {
                if (h[j] == 0) continue;
                int minHeight = h[j];
                for (int k = j; k >= 0; --k) {
                    if (h[k] == 0) break;
                    if (h[k] < minHeight) minHeight = h[k];
                    int currentArea = minHeight * (j - k + 1);
                    if (currentArea > maxArea) {
                        maxArea = currentArea;
                    }
                }
            }
        }

        // De acordo com o formato de saída: uma linha em branco entre os resultados de casos consecutivos
        if (t > 0) cout << "\n";
        cout << maxArea << "\n";
    }

    return 0;
}