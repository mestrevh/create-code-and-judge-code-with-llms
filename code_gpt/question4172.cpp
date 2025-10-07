/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

long long combination(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << combination(n, k) << endl;
    return 0;
}
