/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if ((A == B && B == C) || (A != B && B != C && A != C)) {
        cout << '*';
    } else if (A != B && A != C) {
        cout << 'A';
    } else if (B != A && B != C) {
        cout << 'B';
    } else {
        cout << 'C';
    }

    return 0;
}
