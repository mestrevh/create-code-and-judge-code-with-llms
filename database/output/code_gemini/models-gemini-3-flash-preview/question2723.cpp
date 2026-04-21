/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void processDistribution(string current, unordered_map<string, string>& transitions, unordered_set<string>& visited, vector<string>& result) {
    if (visited.find(current) != visited.end()) {
        return;
    }
    visited.insert(current);
    result.push_back(current);
    if (transitions.count(current)) {
        processDistribution(transitions[current], transitions, visited, result);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    unordered_map<string, string> transitions;
    for (int i = 0; i < n; ++i) {
        string u, v;
        cin >> u >> v;
        transitions[u] = v;
    }

    string startNode;
    cin >> startNode;

    unordered_set<string> visited;
    vector<string> result;

    processDistribution(startNode, transitions, visited, result);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}