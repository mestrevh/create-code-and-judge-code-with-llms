/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Função para contar o número de ocorrências de vogais alienígenas em uma frase.
 * @param vogais String contendo os caracteres que são considerados vogais.
 * @param frase String contendo a frase na qual as vogais serão contadas.
 * @return O número total de vogais encontradas.
 */
int contar_vogais(string vogais, string frase) {
    bool eh_vogal[256];
    for (int i = 0; i < 256; ++i) {
        eh_vogal[i] = false;
    }

    for (char c : vogais) {
        eh_vogal[(unsigned char)c] = true;
    }

    int total = 0;
    for (char c : frase) {
        if (eh_vogal[(unsigned char)c]) {
            total++;
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_casos;
    if (!(cin >> n_casos)) return 0;

    string dummy;
    getline(cin, dummy); // Consome o caractere de nova linha após o número de casos

    while (n_casos--) {
        string vogais_alienigenas, frase;
        
        if (!getline(cin, vogais_alienigenas)) break;
        // Caso ocorra uma linha vazia inesperada entre os casos de teste
        if (vogais_alienigenas.empty()) {
            if (!getline(cin, vogais_alienigenas)) break;
        }

        if (!getline(cin, frase)) break;

        // Remoção de eventual carriage return (\r) em ambientes Windows
        if (!vogais_alienigenas.empty() && vogais_alienigenas.back() == '\r') {
            vogais_alienigenas.pop_back();
        }
        if (!frase.empty() && frase.back() == '\r') {
            frase.pop_back();
        }

        cout << contar_vogais(vogais_alienigenas, frase) << "\n";
    }

    return 0;
}