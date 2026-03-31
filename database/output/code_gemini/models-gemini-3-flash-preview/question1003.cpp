/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problema: Apuração de Loteria
 * Objetivo: Identificar as apostas com maior e menor número de acertos.
 * Complexidade: O(N), onde N é o número de apostas.
 * Cada aposta possui 15 números e existem 10 números sorteados (fixo).
 */

struct Aposta {
    string codigo;
    int acertos;
};

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Armazenar números sorteados em um vetor booleano para consulta O(1)
    bool sorteados[51];
    for (int i = 0; i < 51; ++i) sorteados[i] = false;

    for (int i = 0; i < 10; ++i) {
        int val;
        if (cin >> val) {
            if (val >= 1 && val <= 50) {
                sorteados[val] = true;
            }
        }
    }

    int n;
    if (!(cin >> n)) return 0;

    vector<Aposta> apostas;
    apostas.reserve(n);

    int max_acertos = -1;
    int min_acertos = 11;

    // Processamento de cada aposta
    for (int i = 0; i < n; ++i) {
        string cod;
        if (!(cin >> cod)) break;

        int contagem = 0;
        for (int j = 0; j < 15; ++j) {
            int num;
            if (cin >> num) {
                if (num >= 1 && num <= 50 && sorteados[num]) {
                    contagem++;
                }
            }
        }

        apostas.push_back({cod, contagem});

        // Atualizar limites de acertos encontrados
        if (contagem > max_acertos) max_acertos = contagem;
        if (contagem < min_acertos) min_acertos = contagem;
    }

    if (apostas.empty()) return 0;

    // Função auxiliar para exibir os resultados de uma faixa
    auto imprimir_faixa = [&](int valor_faixa) {
        // Formatação plural/singular para "acerto"
        cout << "Faixa: " << valor_faixa << (valor_faixa == 1 ? " acerto" : " acertos") << "\n";
        
        int total_ganhadores = 0;
        for (const auto& a : apostas) {
            if (a.acertos == valor_faixa) {
                cout << a.codigo << "\n";
                total_ganhadores++;
            }
        }
        
        // Formatação plural/singular para "ganhador"
        cout << total_ganhadores << (total_ganhadores == 1 ? " ganhador" : " ganhadores") << "\n";
    };

    // Exibir faixa de maior número de acertos
    imprimir_faixa(max_acertos);

    // Separar as duas faixas com uma linha em branco conforme exigido
    cout << "\n";

    // Exibir faixa de menor número de acertos
    imprimir_faixa(min_acertos);

    return 0;
}