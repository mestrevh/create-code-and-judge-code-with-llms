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

    int N, E;
    if (!(cin >> N >> E)) return 0;

    vector<int> G(N);
    for (int i = 0; i < N; ++i) {
        cin >> G[i];
    }

    bool found = false;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (G[i] + G[j] == E) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}
