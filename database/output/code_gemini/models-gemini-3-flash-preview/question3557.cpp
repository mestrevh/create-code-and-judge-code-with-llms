/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    while (cin >> a >> b) {
        if (b == 0) continue;

        bool negative = (a < 0) ^ (b < 0);

        unsigned long long A = (a < 0) ? (0ULL - a) : (unsigned long long)a;
        unsigned long long B = (b < 0) ? (0ULL - b) : (unsigned long long)b;

        unsigned long long quotient = 0;

        for (int i = 63; i >= 0; i--) {
            if ((A >> i) >= B) {
                quotient |= (1ULL << i);
                A -= (B << i);
            }
        }

        if (negative && quotient != 0) {
            cout << "-";
        }
        cout << quotient << "\n";
    }

    return 0;
}