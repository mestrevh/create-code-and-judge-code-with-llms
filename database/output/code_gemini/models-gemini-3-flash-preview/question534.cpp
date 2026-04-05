/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        vector<int> n(11);
        for (int j = 0; j < 9; ++j) {
            cin >> n[j];
        }

        int s1 = 0;
        for (int j = 1; j <= 9; ++j) {
            s1 += n[j - 1] * (11 - j);
        }
        int resto1 = s1 % 11;
        int d1 = (resto1 < 2) ? 0 : (11 - resto1);
        n[9] = d1;

        int s2 = 0;
        for (int j = 1; j <= 10; ++j) {
            s2 += n[j - 1] * (12 - j);
        }
        int resto2 = s2 % 11;
        int d2 = (resto2 < 2) ? 0 : (11 - resto2);
        n[10] = d2;

        cout << "Caso " << t << ": ";
        for (int i = 0; i < 9; ++i) {
            cout << n[i];
        }
        cout << "-" << d1 << d2 << "\n";
    }

    return 0;
}