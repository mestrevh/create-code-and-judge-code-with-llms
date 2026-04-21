/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        if (n == 0) {
            cout << "NULO" << "\n";
        } else {
            if (n > 0) {
                cout << "POSITIVO ";
            } else {
                cout << "NEGATIVO ";
            }

            if (n % 2 == 0) {
                cout << "PAR" << "\n";
            } else {
                cout << "IMPAR" << "\n";
            }
        }
    }

    return 0;
}
