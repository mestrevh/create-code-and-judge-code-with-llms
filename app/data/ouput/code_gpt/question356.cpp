/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n > 1) {
        decimalToBinary(n / 2);
    }
    cout << n % 2 << endl;
}

int main() {
    int N;
    cin >> N;
    decimalToBinary(N);
    return 0;
}
