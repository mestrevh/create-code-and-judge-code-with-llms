/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double ph;
    while (true) {
        cin >> ph;
        if (ph == -1) break;
        if (ph < 7) cout << "ACIDA" << endl;
        else if (ph > 7) cout << "BASICA" << endl;
        else cout << "NEUTRA" << endl;
    }
    return 0;
}
