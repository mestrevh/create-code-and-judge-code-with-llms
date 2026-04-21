/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while (cin >> n >> k) {
        if (k <= 0) continue;
        while (n > 0) {
            if (n >= k) {
                cout << k << "\n";
                n -= k;
            } else {
                cout << n << "\n";
                n = 0;
            }
        }
    }

    return 0;
}