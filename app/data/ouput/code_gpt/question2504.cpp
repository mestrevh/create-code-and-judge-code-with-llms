/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string frase;
    getline(cin, frase);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int pos;
        char novo_char;
        cin >> pos >> novo_char;

        if (pos - 1 < frase.length()) {
            frase[pos - 1] = novo_char;
        }
    }

    cout << frase << endl;
    return 0;
}
