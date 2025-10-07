/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countInversions(const string& s) {
    int inversions = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i] > s[j]) {
                ++inversions;
            }
        }
    }
    return inversions;
}

struct DNA {
    string sequence;
    int inversions;

    bool operator<(const DNA& other) const {
        return inversions < other.inversions;
    }
};

int main() {
    int M;
    cin >> M;
    cin.ignore();
    cin.ignore();

    for (int i = 0; i < M; ++i) {
        vector<DNA> dnaList;
        int j, k;
        cin >> j >> k;
        cin.ignore();

        for (int l = 0; l < k; ++l) {
            string seq;
            getline(cin, seq);
            dnaList.push_back({seq, countInversions(seq)});
        }

        sort(dnaList.begin(), dnaList.end());

        for (const auto& dna : dnaList) {
            cout << dna.sequence << endl;
        }

        if (i < M - 1) cout << endl;
    }

    return 0;
}
