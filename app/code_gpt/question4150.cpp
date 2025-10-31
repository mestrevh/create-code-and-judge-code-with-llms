/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int x, y;
    char dir;
    cin >> x >> y >> dir;

    switch (dir) {
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
            cout << "Direcao invalida" << endl;
            return 0;
    }

    cout << "Nova posicao: " << x << " " << y << endl;
    return 0;
}
