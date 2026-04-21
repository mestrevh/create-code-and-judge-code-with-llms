/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long total, per_row, col;
    if (cin >> total >> per_row >> col) {
        for (long long current = col; current <= total; current += per_row) {
            cout << current << "\n";
        }
    }

    return 0;
}