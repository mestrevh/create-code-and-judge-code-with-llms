/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int payment;
    while (true) {
        cin >> payment;
        if (payment == 0) break;
        int notes10 = payment / 10;
        payment %= 10;
        int notes5 = payment / 5;
        payment %= 5;
        int notes1 = payment;
        int totalNotes = notes10 + notes5 + notes1;
        cout << totalNotes << endl;
        cout << notes1 << " " << notes5 << " " << notes10 << endl;
    }
    return 0;
}
