/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A;
        cin >> A;
        if (360 % (180 - A) == 0) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
    }
    return 0;
}
