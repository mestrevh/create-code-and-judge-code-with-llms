/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    if (!(cin >> X >> Y)) return 0;

    int count = 0;
    for (int i = 0; i < X; ++i) {
        int current;
        if (cin >> current) {
            if (current == Y) {
                count++;
            }
        }
    }

    cout << "Digite a quantidade de numeros da sequencia:" << "\n";
    cout << "Digite o numero procurado:" << "\n";
    cout << "O numero " << Y << " apareceu na sequencia " << count << " vezes." << endl;

    return 0;
}