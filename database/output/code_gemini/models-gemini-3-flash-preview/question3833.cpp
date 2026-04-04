/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, C;
    if (!(cin >> A >> C)) return 0;

    for (int i = 0; i < C; ++i) {
        if (30 % (A + 1) == 0) {
            cout << "Curvou\n";
            A++;
        } else {
            cout << "Pedro se cagou todo e foi pego.\n";
            break;
        }
    }

    return 0;
}