/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int num, prev = -1;
    bool inOrder = true;

    while (true) {
        cin >> num;
        if (num == 0) break;
        if (num <= prev) {
            inOrder = false;
        }
        prev = num;
    }

    if (inOrder) {
        cout << "EM ORDEM" << endl;
    } else {
        cout << "FORA DE ORDEM" << endl;
    }

    return 0;
}
