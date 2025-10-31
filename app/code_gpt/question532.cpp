/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int compareWords(const string &a, const string &b, int &compCount) {
    compCount = 0;
    int minLength = min(a.size(), b.size());
    for (int i = 0; i < minLength; ++i) {
        ++compCount;
        if (a[i] != b[i]) {
            return a[i] - b[i];
        }
    }
    compCount += 1; // For the comparison of length
    return a.size() - b.size();
}

pair<string, int> binarySearch(const vector<string> &words, const string &query) {
    int left = 0, right = words.size() - 1, comparisons = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = compareWords(words[mid], query, comparisons);
        if (cmp == 0) {
            return {"SIM", comparisons};
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return {"NAO", comparisons};
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }
    vector<string> queries(M);
    for (int i = 0; i < M; ++i) {
        cin >> queries[i];
    }

    for (const auto &query : queries) {
        auto result = binarySearch(words, query);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
