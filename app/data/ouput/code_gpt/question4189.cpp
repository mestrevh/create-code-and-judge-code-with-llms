/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

long long fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    long long result = fatorial(a) + fatorial(b) + fatorial(c);
    cout << result << endl;
    return 0;
}
