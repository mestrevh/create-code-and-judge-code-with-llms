/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double ph;
    if (cin >> ph) {
        if (ph < 7.0) {
            cout << "Acida" << endl;
        } else if (ph > 7.0) {
            cout << "Basica" << endl;
        } else {
            cout << "Neutra" << endl;
        }
    }

    return 0;
}