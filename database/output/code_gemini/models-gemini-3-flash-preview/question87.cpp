/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<string> dna(n);
        for (int i = 0; i < n; ++i) {
            cin >> dna[i];
        }

        sort(dna.begin(), dna.end());

        vector<int> counts(n + 1, 0);
        int current_cnt = 1;
        for (int i = 1; i <= n; ++i) {
            if (i < n && dna[i] == dna[i - 1]) {
                current_cnt++;
            } else {
                if (current_cnt <= n) {
                    counts[current_cnt]++;
                }
                current_cnt = 1;
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << counts[i] << "\n";
        }
    }

    return 0;
}