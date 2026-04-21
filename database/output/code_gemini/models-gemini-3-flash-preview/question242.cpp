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

    int N;
    if (!(cin >> N)) return 0;

    for (int t = 0; t < N; ++t) {
        int M, C;
        cin >> M >> C;

        vector<vector<int>> table(M);
        for (int i = 0; i < C; ++i) {
            int key;
            cin >> key;
            table[key % M].push_back(key);
        }

        if (t > 0) {
            cout << "\n";
        }

        for (int i = 0; i < M; ++i) {
            cout << i << " -> ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "\\" << "\n";
        }
    }

    return 0;
}

