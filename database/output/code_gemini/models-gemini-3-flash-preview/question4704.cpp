/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Função que inverte uma string utilizando std::reverse do C++.
 * Complexidade de Tempo: O(N), onde N é o comprimento da string.
 * Complexidade de Espaço: O(N) para o retorno da string.
 */
string inverter_string(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string entrada;
    // Utiliza getline para capturar toda a linha, incluindo espaços
    if (getline(cin, entrada)) {
        // Remove possíveis caracteres de controle de fim de linha do Windows (\r)
        if (!entrada.empty() && entrada.back() == '\r') {
            entrada.pop_back();
        }
        cout << inverter_string(entrada) << endl;
    }

    return 0;
}