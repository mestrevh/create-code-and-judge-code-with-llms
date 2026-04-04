/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n;
    if (!(cin >> n)) return 0;

    if (n >= 0 && n <= 25) {
        cout << "Intervalo [0,25]" << endl;
    } else if (n > 25 && n <= 50) {
        cout << "Intervalo (25,50]" << endl;
    } else if (n > 50 && n <= 75) {
        cout << "Intervalo (50,75]" << endl;
    } else if (n > 75 && n <= 100) {
        cout << "Intervalo (75,100]" << endl;
    } else {
        cout << "Fora de intervalo" << endl;
    }

    return 0;
}