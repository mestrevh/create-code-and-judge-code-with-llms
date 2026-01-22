/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void troca(int &A, int &B) {
    if (A > B) {
        int temp = A;
        A = B;
        B = temp;
    }
}

int main() {
    int A, B;
    cin >> A >> B;
    troca(A, B);
    cout << A << " " << B << endl;
    return 0;
}
