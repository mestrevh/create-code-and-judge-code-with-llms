/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int m, int n) {
    return (m / gcd(m, n)) * n;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << lcm(m, n) << endl;
    return 0;
}
