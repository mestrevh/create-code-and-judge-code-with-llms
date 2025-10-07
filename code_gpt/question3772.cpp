/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

long long Fatorial(int n) {
    if (n <= 1) return 1;
    return n * Fatorial(n - 1);
}

int main() {
    int num;
    cin >> num;
    cout << Fatorial(num) << endl;
    return 0;
}
