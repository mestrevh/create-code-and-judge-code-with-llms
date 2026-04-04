/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x1, x2;
    if (cin >> x1 >> x2) {
        long long p = x1 * x2;
        cout << "O produto entre " << x1 << " e " << x2 << " é dado por: " << p << endl;
    }

    return 0;
}