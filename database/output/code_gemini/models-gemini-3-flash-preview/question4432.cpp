/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1;
    if (!(cin >> n1)) return 0;

    if (n1 == 0) {
        int n2;
        if (cin >> n2) {
            for (int i = 0; i < n2; ++i) {
                int q;
                if (cin >> q) cout << "Nao tem ninguem\n";
            }
        }
        return 0;
    }

    vector<string> inputs(n1);
    for (int i = 0; i < n1; ++i) {
        if (!(cin >> inputs[i])) break;
    }

    if (inputs.empty() || inputs[0].empty()) return 0;

    int L = inputs[0].length();
    int K = 0;
    int tempL = L;
    while (tempL > 1) {
        tempL >>= 1;
        K++;
    }

    int M = 1 << K;
    vector<string> table(M, "");
    vector<bool> occupied(M, false);

    for (int i = 0; i < n1; ++i) {
        if (inputs[i].length() < (size_t)K) continue;
        int pos = 0;
        for (int j = 0; j < K; ++j) {
            pos = (pos << 1) | (inputs[i][j] - '0');
        }
        string id = inputs[i].substr(K);

        for (int j = 0; j < M; ++j) {
            int currentPos = (pos + j) % M;
            if (!occupied[currentPos]) {
                table[currentPos] = id;
                occupied[currentPos] = true;
                break;
            }
        }
    }

    int n2;
    if (cin >> n2) {
        for (int i = 0; i < n2; ++i) {
            int q;
            if (!(cin >> q)) break;
            if (q >= 0 && q < M && occupied[q]) {
                cout << table[q] << "\n";
            } else {
                cout << "Nao tem ninguem\n";
            }
        }
    }

    return 0;
}