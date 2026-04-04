/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r;
    while (cin >> l >> r && (l != 0 || r != 0)) {
        cout << (l + r) << "\n";
    }
    return 0;
}