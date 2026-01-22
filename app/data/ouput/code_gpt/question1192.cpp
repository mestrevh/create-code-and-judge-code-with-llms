/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int grains, amount;
    string operation;
    cin >> grains;

    while (cin >> operation >> amount) {
        if (operation == "GUARDAR") {
            grains += amount;
        } else if (operation == "RETIRAR") {
            if (amount > grains) {
                cout << "Winter is here" << endl;
                return 0;
            }
            grains -= amount;
        }
    }
    cout << grains << endl;
    return 0;
}
