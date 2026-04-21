/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Função Calcula:
 * Calcula a concentração acumulada de hidroxilas (OH-) e o pOH da solução.
 * @param concentracaoBase: Ponteiro para a concentração da base adicionada no momento.
 * @param concentracaoTotal: Ponteiro para a concentração acumulada de OH-.
 * @param pOH: Ponteiro para a variável que armazena o valor do pOH calculado.
 * @param indiceHidroxilas: Quantidade de hidroxilas na fórmula da base.
 */
void Calcula(double *concentracaoBase, double *concentracaoTotal, double *pOH, int indiceHidroxilas) {
    // A concentração de hidroxilas é o produto do índice pela concentração da base
    *concentracaoTotal += (*concentracaoBase) * (double)indiceHidroxilas;
    
    // pOH = -log10[OH-]
    if (*concentracaoTotal > 0) {
        *pOH = -log10(*concentracaoTotal);
    }
}

int main() {
    // Otimização de I/O padrão Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double concBase;
    double totalOH = 0.0;
    double pOH = 0.0;
    
    // Leitura contínua da concentração da base até encontrar 0
    while (cin >> concBase && concBase != 0) {
        string elemento, hidroxilaStr;
        int indiceElemento, indiceHidroxilas;
        
        // Leitura da sequência: Elemento, Índice, Hidroxila (OH), Índice
        // Exemplo: Be 1 OH 2
        if (!(cin >> elemento >> indiceElemento >> hidroxilaStr >> indiceHidroxilas)) {
            break;
        }
        
        // Chamada da função obrigatória manipulando valores via ponteiros
        Calcula(&concBase, &totalOH, &pOH, indiceHidroxilas);
        
        // Cálculo do pH na escala Franjinha: pH = 9 - pOH
        // Equivalente a: pH = 9 + log10(totalOH)
        double pH = 9.0 - pOH;
        
        // Saída formatada com uma casa decimal conforme casos de teste
        cout << fixed << setprecision(1) << pH << "\n";
    }

    return 0;
}