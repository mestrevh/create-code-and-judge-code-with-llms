/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    long long T;
    cin >> T;

    while (T--) {
        long long a, b, m;
        cin >> a >> b >> m;
        cout << (a % m * b % m) % m << endl;
    }

    return 0;
}
