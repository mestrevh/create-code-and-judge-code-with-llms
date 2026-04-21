/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D;
    if (!(cin >> D)) return 0;

    if (D <= 10) {
        cout << "Arthur" << endl;
    } else if (D <= 30) {
        cout << "Luiz" << endl;
    } else if (D <= 100) {
        cout << "Pedro" << endl;
    } else {
        cout << "Nenhum" << endl;
    }

    return 0;
}