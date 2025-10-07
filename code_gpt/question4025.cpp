/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int shake1, shake2, ml1, ml2, R;
    cin >> shake1 >> shake2 >> ml1 >> ml2 >> R;

    int price1 = (shake1 == 1) ? 2 : (shake1 == 2) ? 3 : 4;
    int price2 = (shake2 == 1) ? 2 : (shake2 == 2) ? 3 : 4;

    int discount1 = (ml1 <= 500) ? 5 : 10;
    int discount2 = (ml2 <= 500) ? 3 : 6;

    int finalPrice1 = (ml1 / 100) * price1 * (100 - discount1) / 100;
    int finalPrice2 = (ml2 / 100) * price2 * (100 - discount2) / 100;

    int totalCost = finalPrice1 + finalPrice2;

    if (totalCost > R) {
        cout << "Carambolas! O shake JA ERA.\n";
    } else {
        int maxMultiple = (R / totalCost);
        if (maxMultiple > 1) {
            cout << "Yeah! Shake " << maxMultiple << " vezes mais.\n";
        } else {
            cout << "De qualquer forma matamos nossa sede de shake.\n";
        }
    }

    return 0;
}
