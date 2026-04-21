/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    char cmd;

    if (!(cin >> x >> y >> cmd)) return 0;

    bool valid = true;
    switch (cmd) {
        case 'w':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 's':
            y--;
            break;
        case 'd':
            x++;
            break;
        default:
            valid = false;
            break;
    }

    if (valid) {
        cout << "Nova posicao: " << x << " " << y << "\n";
    } else {
        cout << "Direcao invalida" << "\n";
    }

    return 0;
}