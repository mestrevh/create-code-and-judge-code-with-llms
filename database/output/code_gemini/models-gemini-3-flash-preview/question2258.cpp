/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

void exibirQuantidade(string s) {
    int contador = 0;
    while (s[contador] != '\0') {
        contador++;
    }
    cout << contador << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (getline(cin, s)) {
        exibirQuantidade(s);
    }

    return 0;
}