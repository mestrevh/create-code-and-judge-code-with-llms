/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int level;
    cin >> level;
    int power;

    if (level >= 1 && level <= 20) {
        power = 20 + (level * level * level);
    } else if (level >= 21 && level <= 40) {
        power = 8000 + ((level - 10) * (level - 10));
    } else if (level >= 41 && level <= 60) {
        power = 9000 + 5 * level;
    } else if (level >= 61 && level <= 80) {
        power = 9300 + 2 * level;
    } else if (level >= 81 && level <= 100) {
        power = 9500 + level;
    }

    cout << "Potencia de : " << power << " W" << endl;
    return 0;
}
