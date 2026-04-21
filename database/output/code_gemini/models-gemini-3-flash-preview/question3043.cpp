/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    if (cin >> a >> b >> c) {
        if (a < b) {
            // Se a temperatura subiu do 1º para o 2º
            if (b >= c) {
                // mas desceu ou permaneceu constante do 2º para o 3º (segunda figura)
                cout << ":(\n";
            } else if (c - b < b - a) {
                // ou se subiu do 2º para o 3º menos do que subira do 1º para o 2º (terceira figura)
                cout << ":(\n";
            } else {
                // caso contrário (incluindo quarta figura: subiu igual ou mais)
                cout << ":)\n";
            }
        } else if (a > b) {
            // Se a temperatura desceu do 1º para o 2º
            if (b <= c) {
                // mas subiu ou permaneceu constante do 2º para o 3º (inclui primeira figura)
                cout << ":)\n";
            } else if (b - c < a - b) {
                // ou se desceu do 2º para o 3º menos do que descera do 1º para o 2º (quinta figura)
                cout << ":)\n";
            } else {
                // se desceu do 2º para o 3º no mínimo o tanto que descera do 1º para o 2º (sexta figura)
                cout << ":(\n";
            }
        } else {
            // Se a temperatura permaneceu constante do 1º para o 2º
            if (c < b) {
                // tristes se baixou do 2º para o 3º (oitava figura)
                cout << ":(\n";
            } else {
                // qualquer outro caso (inclui sétima figura: subiu; e nono caso: constante)
                cout << ":)\n";
            }
        }
    }

    return 0;
}