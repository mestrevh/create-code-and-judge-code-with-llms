/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int idade;
    if (!(cin >> idade)) return 0;

    if (idade < 16) {
        cout << "nao eleitor" << endl;
    } else if (idade >= 18 && idade <= 65) {
        cout << "eleitor obrigatorio" << endl;
    } else {
        cout << "eleitor facultativo" << endl;
    }

    return 0;
}