/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

/**
 * Grande Mestre de Programação Competitiva
 * Solução: Cadastro de Animais do Zoológico
 * Complexidade: O(N), onde N é o número de caracteres na entrada.
 */

// Função auxiliar para converter string para minúsculo para comparação case-insensitive
string to_lower(string s) {
    for (char &c : s) {
        c = (char)tolower((unsigned char)c);
    }
    return s;
}

int main() {
    // Otimização de I/O padrão em C++ para maratonas de programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tipo, pais, cmd;
    double peso;

    // Variáveis para acumular os resultados solicitados
    int macacos = 0;
    int tigres_count = 0;
    double tigres_peso_soma = 0.0;
    int cobras_venezuela = 0;

    /**
     * De acordo com o formato de entrada: tipo (String), peso (real), país (String).
     * Após esses três valores, um comando (String) indica se o processo deve continuar.
     * O loop deve ser encerrado se o comando for "PARAR" (case-insensitive).
     */
    while (cin >> tipo >> peso >> pais >> cmd) {
        string tl = to_lower(tipo);
        string pl = to_lower(pais);
        string cl = to_lower(cmd);

        // 1. Contagem de macacos
        if (tl == "macaco") {
            macacos++;
        } 
        // 2. Acúmulo de dados para o peso médio dos tigres
        else if (tl == "tigre") {
            tigres_count++;
            tigres_peso_soma += peso;
        } 
        // 3. Contagem de cobras vindas da Venezuela
        else if (tl == "cobra") {
            if (pl == "venezuela") {
                cobras_venezuela++;
            }
        }

        // Critério de parada: comando igual a "PARAR"
        if (cl == "parar") {
            break;
        }
    }

    // Cálculo do peso médio dos tigres (evitando divisão por zero)
    double media_tigres = 0.0;
    if (tigres_count > 0) {
        media_tigres = tigres_peso_soma / (double)tigres_count;
    }

    /**
     * Saída Formatada:
     * 1. Quantidade de macacos (Inteiro)
     * 2. Peso médio dos tigres (Real com 2 casas decimais)
     * 3. Quantidade de cobras da Venezuela (Inteiro)
     */
    cout << macacos << "\n";
    cout << fixed << setprecision(2) << media_tigres << "\n";
    cout << cobras_venezuela << endl;

    return 0;
}