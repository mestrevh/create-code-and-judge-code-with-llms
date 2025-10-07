/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool ehDivisivel(int A, int B) {
    return A % B == 0;
}

int main() {
    int A, B;
    cin >> A >> B;
    if (ehDivisivel(A, B)) {
        cout << "divisivel" << endl;
    } else {
        cout << "nao divisivel" << endl;
    }
    return 0;
}
