/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    char X;

    if (!(cin >> L >> C >> X)) return 0;

    string row(C, X);
    for (int i = 0; i < L; ++i) {
        cout << row << "\n";
    }

    return 0;
}