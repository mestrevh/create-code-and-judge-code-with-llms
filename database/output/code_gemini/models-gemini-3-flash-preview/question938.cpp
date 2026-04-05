/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a;
    int negative_count = 0;

    for (int i = 0; i < 5; ++i) {
        cout << "Digite um valor:" << "\n";
        if (cin >> a) {
            if (a < 0) {
                negative_count++;
            }
        }
    }

    cout << "Foram digitados " << negative_count << " numeros negativos" << endl;

    return 0;
}