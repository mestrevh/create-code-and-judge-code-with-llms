/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long b, m, v;
    if (!(cin >> b >> m >> v)) return 0;

    char c;
    long long e;
    if (!(cin >> c >> e)) return 0;

    long long total = b + m + v;

    if (e <= 0 || e > total) {
        cout << "You pensa que me engana, vou te mostrar a glocada de 30!" << endl;
    } else {
        long long diff = total - e;
        if (c == 'B') {
            if (diff % 7 == 0) {
                cout << "Parabens pobre, ganhou uma box of good good" << endl;
            } else {
                cout << "Not my problema" << endl;
            }
        } else if (c == 'M') {
            if ((diff % 3 == 0 && diff % 2 != 0) || (diff % 8 == 0)) {
                cout << "Acui, uma box of good good for you, alright?" << endl;
            } else {
                cout << "Deixei sua box of good good la em Xique-Xique Bahia" << endl;
            }
        } else if (c == 'V') {
            if (diff % 2 != 0 || diff % 5 == 0) {
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