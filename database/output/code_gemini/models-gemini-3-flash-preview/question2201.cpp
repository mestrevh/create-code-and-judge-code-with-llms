/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    int type1 = (L * C) + ((L - 1) * (C - 1));
    int type2 = 2 * (L - 1) + 2 * (C - 1);

    cout << type1 << "\n" << type2 << "\n";

    return 0;
}