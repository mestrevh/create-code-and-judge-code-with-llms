/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool predecessorOuSucessor(unsigned int n, int x) {
    while (n > 0) {
        int digito = n % 10;
        if (digito == x - 1 || digito == x + 1) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    unsigned int n;
    int x;
    cin >> n >> x;
    if (predecessorOuSucessor(n, x)) {
        cout << "sim" << endl;
    } else {
        cout << "nao" << endl;
    }
    return 0;
}
