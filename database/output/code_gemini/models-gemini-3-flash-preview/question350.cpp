/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    if (!(cin >> S)) return 0;

    int L = 0, R = 100;
    int G;
    while (cin >> G) {
        if (G == S) {
            cout << "Voce bebe!\n";
            break;
        }

        if (G < S) {
            if (G > L) {
                L = G;
            }
        } else if (G > S) {
            if (G < R) {
                R = G;
            }
        }

        if (L == S - 1 && R == S + 1) {
            cout << "Ambrosio bebe!\n";
            break;
        } else {
            cout << "Escolha um numero entre " << L << " e " << R << "!\n";
        }
    }

    return 0;
}