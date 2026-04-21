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

    long long current_grains;
    if (!(cin >> current_grains)) {
        return 0;
    }

    string operation;
    long long quantity;
    bool winter_is_here = false;

    while (cin >> operation >> quantity) {
        if (operation == "GUARDAR") {
            current_grains += quantity;
        } else if (operation == "RETIRAR") {
            if (quantity > current_grains) {
                winter_is_here = true;
                break;
            } else {
                current_grains -= quantity;
            }
        }
    }

    if (winter_is_here) {
        cout << "Winter is here" << endl;
    } else {
        cout << current_grains << endl;
    }

    return 0;
}