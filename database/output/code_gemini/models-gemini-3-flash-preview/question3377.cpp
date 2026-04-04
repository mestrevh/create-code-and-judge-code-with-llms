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
    if (cin >> idade) {
        if (idade >= 18) {
            cout << "maior de idade" << endl;
        } else {
            cout << "menor de idade" << endl;
        }
    }

    return 0;
}