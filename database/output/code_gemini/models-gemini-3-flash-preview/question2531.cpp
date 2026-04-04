/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n;
    cout << "Digite um numero:\n";
    if (cin >> n) {
        if (n > 10) {
            cout << "O numero e maior que 10\n";
        }
    }

    return 0;
}