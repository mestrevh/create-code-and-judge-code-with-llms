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

    if (idade >= 18) {
        cout << "Maior de Idade" << endl;
    } else {
        cout << "Menor de Idade" << endl;
    }

    return 0;
}