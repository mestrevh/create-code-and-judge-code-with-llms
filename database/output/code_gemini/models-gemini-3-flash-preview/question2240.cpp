/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long C, L;
    if (!(cin >> C >> L)) return 0;

    string s1, s2, tipo;
    cin >> s1;
    if (s1 == "Bola") {
        cin >> s2;
        tipo = s1 + " " + s2;
    } else {
        tipo = s1;
    }

    long long X, Y;
    if (!(cin >> X >> Y)) return 0;

    bool rebatida = false;
    bool in_width = (Y >= 0 && Y <= L);

    if (in_width && X > 0) {
        if (tipo == "Saque") {
            if (4 * X <= C) {
                rebatida = true;
            }
        } else {
            if (2 * X <= C) {
                rebatida = true;
            }
        }
    }

    if (rebatida) {
        cout << "A bola foi rebatida" << endl;
    } else {
        cout << "A bola foi para fora" << endl;
    }

    return 0;
}