/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long attacks[3];
    bool has_zero = false;

    for (int i = 0; i < 3; ++i) {
        if (!(cin >> attacks[i])) break;
        if (attacks[i] == 0) {
            has_zero = true;
        }
    }

    if (has_zero) {
        cout << "Nao" << endl;
        return 0;
    }

    bool defeated = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i != j) {
                if (attacks[i] > 10 && attacks[j] % 2 == 0) {
                    defeated = true;
                }
            }
        }
    }

    if (defeated) {
        cout << "Sim" << endl;
    } else {
        cout << "Nao" << endl;
    }

    return 0;
}