/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    int n;

    if (!(cin >> a >> b >> n)) {
        return 0;
    }

    if (n >= 1) {
        cout << a << "\n";
    }
    if (n >= 2) {
        cout << b << "\n";
    }

    long long prev2 = a;
    long long prev1 = b;

    for (int i = 3; i <= n; ++i) {
        long long current;
        if (i % 2 != 0) {
            current = prev1 + prev2;
        } else {
            current = prev1 - prev2;
        }
        cout << current << "\n";
        prev2 = prev1;
        prev1 = current;
    }

    return 0;
}