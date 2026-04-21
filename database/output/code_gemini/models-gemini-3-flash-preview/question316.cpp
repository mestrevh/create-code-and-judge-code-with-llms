/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        int l;
        if (!(cin >> l)) break;

        long long total_hash = 0;
        for (int i = 0; i < l; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < (int)s.length(); ++j) {
                // Valor = (Posição no alfabeto) + (Elemento de entrada) + (Posição do elemento)
                // Posição no alfabeto: 'A'=0, 'B'=1, ...
                // Elemento de entrada: index da string no caso de teste (i)
                // Posição do elemento: index do caractere na string (j)
                total_hash += (s[j] - 'A') + i + j;
            }
        }
        cout << total_hash << "\n";
    }

    return 0;
}