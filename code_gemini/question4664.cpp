/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    int b, m, v, e;
    char c;
    cin >> b >> m >> v >> c >> e;
    int total = b + m + v;
    if (e <= 0 || e > total) {
        cout << "You pensa que me engana, vou te mostrar a glocada de 30!" << endl;
    } else {
        if (c == 'B') {
            if ((total - e) % 7 == 0) {
                cout << "Parabens pobre, ganhou uma box of good good" << endl;
            } else {
                cout << "Not my problema" << endl;
            }
        } else if (c == 'M') {
            if (((total - e) % 3 == 0 && (total - e) % 2 != 0) || (total - e) % 8 == 0) {
                cout << "Acui, uma box of good good for you, alright?" << endl;
            } else {
                cout << "Deixei sua box of good good la em Xique-Xique Bahia" << endl;
            }
        } else if (c == 'V') {
            if ((total - e) % 2 != 0 || (total - e) % 5 == 0) {
                cout << "HEEHEE, good good for you" << endl;
            } else {
                cout << "Sem good good for you, alright?" << endl;
            }
        } else {
            cout << "Ta querendo enganar quem, POBRE?!" << endl;
        }
    }
    return 0;
}
