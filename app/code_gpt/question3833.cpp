/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, C;
    cin >> A >> C;
    for (int i = 0; i < C; i++) {
        if ((A + 1) % 30 == 0) {
            cout << "Curvou" << endl;
        } else {
            cout << "Pedro se cagou todo e foi pego." << endl;
            break;
        }
        A++;
    }
    return 0;
}
