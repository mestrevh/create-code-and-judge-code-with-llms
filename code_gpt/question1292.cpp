/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N;
    cin >> N;
    int concentration = fibonacci(N);
    if (concentration == 0) {
        cout << "O antidoto nao e necessario" << endl;
    } else {
        cout << concentration << " mg/L" << endl;
    }
    return 0;
}
