/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double ph;
    cin >> ph;
    if (ph < 7) {
        cout << "Acida" << endl;
    } else if (ph > 7) {
        cout << "Basica" << endl;
    } else {
        cout << "Neutra" << endl;
    }
    return 0;
}
