/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int diff = abs(A - B);
    int moves = diff / 3 + (diff % 3) / 2 + (diff % 3) % 2;

    cout << moves << endl;
    return 0;
}
