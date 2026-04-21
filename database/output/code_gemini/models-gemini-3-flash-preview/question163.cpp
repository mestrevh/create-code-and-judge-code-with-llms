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

    int P, N;
    if (!(cin >> P >> N)) return 0;

    vector<int> counts(P + 1, 0);
    for (int i = 0; i < N; ++i) {
        int pos;
        if (cin >> pos) {
            if (pos >= 1 && pos <= P) {
                counts[pos]++;
            }
        }
    }

    int k = N / P;
    int R = N % P;

    bool possible = true;
    for (int i = 1; i <= P; ++i) {
        int expected = (i <= R) ? (k + 1) : k;
        if (counts[i] != expected) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "S" << "\n";
    } else {
        cout << "N" << "\n";
    }

    return 0;
}