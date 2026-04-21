/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line1, line2;
    while (getline(cin, line1)) {
        if (!getline(cin, line2)) break;

        // Limpeza de caracteres de nova linha (CRLF) para garantir portabilidade
        if (!line1.empty() && line1.back() == '\r') line1.pop_back();
        if (!line2.empty() && line2.back() == '\r') line2.pop_back();

        set<string> words1, words2;
        string word;
        int total1 = 0, total2 = 0;

        // Processamento do primeiro texto
        stringstream ss1(line1);
        while (ss1 >> word) {
            words1.insert(word);
            total1++;
        }

        // Processamento do segundo texto
        stringstream ss2(line2);
        while (ss2 >> word) {
            words2.insert(word);
            total2++;
        }

        // Cálculo de repetições únicas (interseção dos conjuntos de palavras)
        int uniqueRepetitions = 0;
        for (const string& w : words1) {
            if (words2.count(w)) {
                uniqueRepetitions++;
            }
        }

        // Cálculo do índice de plágio conforme a fórmula:
        // (repetições únicas / total de palavras de ambos) * 100
        int totalWords = total1 + total2;
        if (totalWords == 0) {
            cout << fixed << setprecision(1) << 0.0 << endl;
        } else {
            double plagiarismIndex = (double)uniqueRepetitions / totalWords * 100.0;
            cout << fixed << setprecision(1) << plagiarismIndex << endl;
        }
    }

    return 0;
}