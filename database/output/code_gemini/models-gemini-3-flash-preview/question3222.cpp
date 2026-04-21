/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Processa a entrada enquanto houver dados (suporta múltiplos casos de teste)
    while (cin >> s) {
        // Caso base para o número zero
        if (s == "0" || s == "-0") {
            cout << "0\n";
            continue;
        }

        // Tratamento de sinal negativo
        bool negative = false;
        if (!s.empty() && s[0] == '-') {
            negative = true;
            s.erase(0, 1);
        }

        // Inversão dos dígitos
        reverse(s.begin(), s.end());

        // Remoção de zeros à esquerda após a inversão (ex: 120 -> 021 -> 21)
        size_t first_non_zero = s.find_first_not_of('0');
        
        if (first_non_zero == string::npos) {
            // Se todos os caracteres eram zeros
            cout << "0\n";
        } else {
            // Se o número era negativo, imprime o sinal antes do valor invertido
            if (negative) cout << "-";
            cout << s.substr(first_non_zero) << "\n";
        }
    }

    return 0;
}