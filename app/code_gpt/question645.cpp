/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> disc, low;
vector<bool> inStack;
vector<int> stack;
int time = 0;
bool isStronglyConnected = true;

void dfs(int u) {
    disc[u] = low[u] = ++time;
    stack.push_back(u);
    inStack[u] = true;

    for (int v : graph[u]) {
        if (disc[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        int w = -1;
        while (w != u) {
            w = stack.back();
            stack.pop_back();
            inStack[w] = false;
        }
    }
}

bool canTransport(int N) {
    graph.clear();
    graph.resize(N + 1);
    disc.assign(N + 1, -1);
    low.assign(N + 1, -1);
    inStack.assign(N + 1, false);
    time = 0;

    for (int i = 1; i <= N; i++) {
        if (disc[i] == -1) {
            dfs(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (disc[i] == -1) {
            return false; // Graph is not connected
        }
    }
    return isStronglyConnected;
}

int main() {
    int N, M;
    while (cin >> N >> M && (N || M)) {
        graph.clear();
        graph.resize(N + 1);
        for (int i = 0; i < M; i++) {
            int A, B;
            cin >> A >> B;
            graph[A].push_back(B);
            graph[B].push_back(A);
        }

        if (canTransport(N)) cout << "S\n";
        else cout << "N\n";
    }
    return 0;
}
