/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A == 0 && B == 0) {
        cout << (C == 0 ? "S" : "N") << endl;
    } else if (A == 0) {
        cout << (C % B == 0 ? "S" : "N") << endl;
    } else if (B == 0) {
        cout << (C % A == 0 ? "S" : "N") << endl;
    } else {
        cout << (C % __gcd(A, B) == 0 ? "S" : "N") << endl;
    }
    return 0;
}
