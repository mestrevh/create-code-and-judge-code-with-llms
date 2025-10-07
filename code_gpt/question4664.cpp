/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int b, m, v, e;
    char c;
    cin >> b >> m >> v;
    int total = b + m + v;
    cin >> c >> e;
    
    if (e <= 0 || e > total) {
        cout << "You pensa que me engana, vou te mostrar a glocada de 30!" << endl;
        return 0;
    }
    
    int diff = total - e;
    bool won = false;

    switch (c) {
        case 'B':
            won = (diff % 7 == 0);
            cout << (won ? "Parabens pobre, ganhou uma box of good good" : "Not my problema") << endl;
            break;
        case 'M':
            won = (diff % 3 == 0 && diff % 2 != 0) || (diff % 8 == 0);
            cout << (won ? "Acui, uma box of good good for you, alright?" : "Deixei sua box of good good la em Xique-Xique Bahia") << endl;
            break;
        case 'V':
            won = (diff % 2 != 0) || (diff % 5 == 0);
            cout << (won ? "HEEHEE, good good for you" : "Sem good good for you, alright?") << endl;
            break;
        default:
            cout << "Ta querendo enganar quem, POBRE?!" << endl;
            break;
    }
    
    return 0;
}
