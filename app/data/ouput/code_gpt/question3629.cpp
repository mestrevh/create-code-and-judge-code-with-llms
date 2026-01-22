/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string mensagem;
    int k;
    cin >> mensagem >> k;
    string resultado;

    for (char c : mensagem) {
        if (isalpha(c)) {
            char base = 'a' + (isupper(c) ? 0 : 0);
            resultado += (c - base + k) % 26 + base;
        } else {
            resultado += c;
        }
    }

    cout << resultado << endl;
    return 0;
}
