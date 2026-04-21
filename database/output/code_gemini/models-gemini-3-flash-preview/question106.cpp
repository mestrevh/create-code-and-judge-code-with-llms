/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long fib[48];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 48; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n;
    while (cin >> n && n != 0) {
        if (n <= 0) continue;
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << fib[i];
        }
        cout << "\n";
    }

    return 0;
}