/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long cp;
    if (!(cin >> cp)) return 0;

    if (cp >= 1000 && cp <= 9999) {
        int ab = cp / 100;
        int cd = cp % 100;
        int ef = ab + cd;
        if (ef * ef == cp) {
            cout << "Charmander vitorioso" << endl;
        } else {
            cout << "Charmander derrotado" << endl;
        }
    } else {
        cout << "Charmander derrotado" << endl;
    }

    return 0;
}