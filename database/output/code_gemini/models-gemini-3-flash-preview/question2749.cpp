/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, R;
    while (cin >> L >> R && (L != 0 || R != 0)) {
        cout << (L + R) << "\n";
    }

    return 0;
}