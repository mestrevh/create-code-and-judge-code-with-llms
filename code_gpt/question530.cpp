/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<string, int> binarySearch(const vector<string>& words, const string& query) {
    int left = 0, right = words.size() - 1, comparisons = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        comparisons++;
        if (words[mid] == query) {
            return {"SIM", comparisons};
        } else if (words[mid] < query) {
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
    vector<pair<string, int>> results(M);
    for (int i = 0; i < M; ++i) {
        string query;
        cin >> query;
        results[i] = binarySearch(words, query);
    }
    for (const auto& result : results) {
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
