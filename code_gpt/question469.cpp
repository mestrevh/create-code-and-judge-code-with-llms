/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int reinaldo = 0, helena = 0, pontosReinaldo = 0, pontosHelena = 0;

    for (int i = 0; i < 5; i++) {
        int r, h;
        cin >> r >> h;
        if (r > h) {
            reinaldo++;
            pontosReinaldo += r;
        } else if (h > r) {
            helena++;
            pontosHelena += h;
        } else {
            pontosReinaldo += r;
            pontosHelena += h;
        }
    }

    if (reinaldo > helena) {
        cout << "REINALDO" << endl;
    } else if (helena > reinaldo) {
        cout << "HELENA" << endl;
    } else {
        cout << "EMPATE" << endl;
    }

    return 0;
}
