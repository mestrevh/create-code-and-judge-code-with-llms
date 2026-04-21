/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long L, A, P, R;
    if (cin >> L >> A >> P >> R) {
        if (L * L + A * A + P * P <= 4 * R * R) {
            cout << 'S' << endl;
        } else {
            cout << 'N' << endl;
        }
    }
    return 0;
}