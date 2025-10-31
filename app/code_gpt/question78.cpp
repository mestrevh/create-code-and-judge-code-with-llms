/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    string frase;
    while (getline(cin, frase)) {
        if (frase == "NAO QUERO MAIS") break;

        int espacos = 0, a_count = 0;
        map<string, int> pares;
        
        for (size_t i = 0; i < frase.length(); i++) {
            if (frase[i] == ' ') espacos++;
            if (tolower(frase[i]) == 'a') a_count++;

            if (i < frase.length() - 1 && isalpha(frase[i]) && isalpha(frase[i + 1])) {
                string par = tolower(frase[i]) + string(1, tolower(frase[i + 1]));
                pares[par]++;
            }
        }

        cout << espacos << endl;
        cout << a_count << endl;

        if (pares.empty()) {
            cout << "NENHUM PAR" << endl;
        } else {
            string mais_frequente;
            int max_freq = 0;

            for (const auto& p : pares) {
                if (p.second > max_freq) {
                    max_freq = p.second;
                    mais_frequente = p.first;
                }
            }
            cout << max_freq << endl;
            cout << mais_frequente << endl;
        }
    }
    return 0;
}
