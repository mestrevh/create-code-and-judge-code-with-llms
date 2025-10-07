/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned int N, P, Q;
    char C;

    cin >> N >> P >> C >> Q;

    if (C == '+') {
        if (P > N - Q) {
            cout << "OVERFLOW" << endl;
        } else {
            cout << "OK" << endl;
        }
    } else if (C == '*') {
        if (P > N / Q) {
            cout << "OVERFLOW" << endl;
        } else {
            cout << "OK" << endl;
        }
    }

    return 0;
}
