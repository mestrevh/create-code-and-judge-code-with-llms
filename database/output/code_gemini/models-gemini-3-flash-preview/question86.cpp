/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct DNA {
    string seq;
    int inv;
};

int countInversions(const string& s) {
    int inversions = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] > s[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

bool compareDNA(const DNA& a, const DNA& b) {
    return a.inv < b.inv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;

    while (M--) {
        int j, k;
        if (!(cin >> j >> k)) break;

        vector<DNA> dataset(k);
        for (int i = 0; i < k; ++i) {
            cin >> dataset[i].seq;
            dataset[i].inv = countInversions(dataset[i].seq);
        }

        stable_sort(dataset.begin(), dataset.end(), compareDNA);

        for (int i = 0; i < k; ++i) {
            cout << dataset[i].seq << "\n";
        }

        if (M > 0) {
            cout << "\n";
        }
    }

    return 0;
}