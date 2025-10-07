/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& bananas, int& sum) {
    visited[node] = true;
    sum += bananas[node];
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, bananas, sum);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> graph(N);
        for (int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;
            graph[A - 1].push_back(B - 1);
            graph[B - 1].push_back(A - 1);
        }
        
        vector<int> bananas(N);
        for (int i = 0; i < N; i++) {
            cin >> bananas[i];
        }

        vector<bool> visited(N, false);
        int maxCoins = 0;

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                int sum = 0;
                dfs(i, graph, visited, bananas, sum);
                maxCoins = max(maxCoins, sum);
            }
        }
        cout << maxCoins << endl;
    }
    return 0;
}
