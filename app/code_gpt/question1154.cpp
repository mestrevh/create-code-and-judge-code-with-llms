/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int P, S, T;
    cin >> P >> S >> T;

    if (P == 0 || S == 0 || T == 0) {
        cout << "Não" << endl;
    } else if ((P > 10 || S > 10 || T > 10) && (P % 2 == 0 || S % 2 == 0 || T % 2 == 0)) {
        cout << "Sim" << endl;
    } else {
        cout << "Não" << endl;
    }

    return 0;
}
