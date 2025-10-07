/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float nota;
    cin >> nota;

    if (nota > 7) {
        cout << "bolinha verde" << endl;
    } else if (nota >= 5) {
        cout << "bolinha amarela" << endl;
    } else {
        cout << "bolinha vermelha" << endl;
    }

    return 0;
}
