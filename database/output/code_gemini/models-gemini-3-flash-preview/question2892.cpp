/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    cout << "Digite a ordem N da matriz:" << "\n";

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int val;
            if (i == j) {
                val = 1;
            } else if (i < j) {
                val = 10;
            } else {
                val = -10;
            }
            cout << left << setw(7) << val;
        }
        cout << "\n";
    }

    return 0;
}