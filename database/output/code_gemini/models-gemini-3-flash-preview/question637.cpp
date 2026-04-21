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

    int P, N, C;
    while (cin >> P >> N >> C && (P != 0 || N != 0 || C != 0)) {
        vector<int> current_palito_len(P, 0);
        int total_count = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < P; ++j) {
                int bit;
                cin >> bit;
                if (bit == 1) {
                    current_palito_len[j]++;
                } else {
                    if (current_palito_len[j] >= C) {
                        total_count++;
                    }
                    current_palito_len[j] = 0;
                }
            }
        }

        for (int j = 0; j < P; ++j) {
            if (current_palito_len[j] >= C) {
                total_count++;
            }
        }

        cout << total_count << "\n";
    }

    return 0;
}
