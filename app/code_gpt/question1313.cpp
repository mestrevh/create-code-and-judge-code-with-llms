/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    if (p1 < p2 && p1 < p3) {
        cout << "Primeiro produto" << endl;
    } else if (p2 < p1 && p2 < p3) {
        cout << "Segundo produto" << endl;
    } else {
        cout << "Terceiro produto" << endl;
    }

    return 0;
}
