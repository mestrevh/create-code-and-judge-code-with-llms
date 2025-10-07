/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int D;
    cin >> D;

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
