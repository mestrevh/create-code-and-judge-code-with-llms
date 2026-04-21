/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        unsigned long long a, b;
        if (!(cin >> a >> b)) break;
        unsigned long long diff = a ^ b;
        cout << __builtin_popcountll(diff) << "\n";
    }

    return 0;
}