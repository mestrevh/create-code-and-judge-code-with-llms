/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int X, Y;
    cout << "Digite a quantidade de numeros da sequencia:" << endl;
    cin >> X;
    cout << "Digite o numero procurado:" << endl;
    cin >> Y;

    int count = 0;
    for (int i = 0; i < X; ++i) {
        int num;
        cin >> num;
        if (num == Y) {
            count++;
        }
    }

    cout << "O numero " << Y << " apareceu na sequencia " << count << " vezes." << endl;
    return 0;
}
