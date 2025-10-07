/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void countPaths(const string& start, const string& end, unordered_map<string, vector<string>>& graph, unordered_map<string, int>& memo) {
    if (start == end) return;
    if (memo.count(start)) return;
    
    memo[start] = 0;
    for (const string& neighbor : graph[start]) {
        countPaths(neighbor, end, graph, memo);
        memo[start] += memo[neighbor];
    }
}

int main() {
    int n;
    cin >> n;
    unordered_map<string, vector<string>> graph;
    string place, destination;

    for (int i = 0; i < n; i++) {
        vector<string> neighbors;
        while (cin >> place && (place != "eol")) {
            neighbors.push_back(place);
        }
        graph[neighbors[0]] = vector<string>(neighbors.begin() + 1, neighbors.end());
    }

    cin >> place >> destination;

    unordered_map<string, int> memo;
    memo[destination] = 1; // 1 way to reach the destination from itself

    countPaths(place, destination, graph, memo);
    cout << memo[place] << endl;

    return 0;
}
