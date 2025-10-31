/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int distance;
    int predecessor;
};

void bfs(int start, int end, const vector<vector<int>>& graph, vector<Node>& nodes) {
    queue<int> q;
    q.push(start);
    nodes[start].distance = 0;
    nodes[start].predecessor = -1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Iniciando busca em largura a partir de " << current << endl;
        
        for (int neighbor : graph[current]) {
            if (nodes[neighbor].distance == -1) {
                nodes[neighbor].distance = nodes[current].distance + 1;
                nodes[neighbor].predecessor = current;
                q.push(neighbor);
            }
        }
    }
}

void printResults(int testCase, int start, int end, const vector<Node>& nodes) {
    cout << "Caso de Teste #" << testCase << " - BFS(" << start << ")" << endl;
    for (size_t i = 0; i < nodes.size(); i++) {
        cout << i << " | ";
        if (nodes[i].distance == -1) {
            cout << "- | -";
        } else {
            cout << nodes[i].distance << " | " << nodes[i].predecessor;
        }
        cout << endl;
    }

    if (nodes[end].distance == -1) {
        cout << "Sem caminho entre " << start << " e " << end << endl;
    } else {
        cout << "Caminho entre " << start << " e " << end << ": ";
        vector<int> path;
        for (int at = end; at != -1; at = nodes[at].predecessor) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " => ";
        }
        cout << endl;
    }
}

int main() {
    int V, A, T;
    cin >> V >> A >> T;
    vector<vector<int>> graph(V);
    
    for (int i = 0; i < A; i++) {
        int O, D;
        cin >> O >> D;
        graph[O].push_back(D);
        graph[D].push_back(O);
    }

    for (int i = 0; i < T; i++) {
        int start, end;
        cin >> start >> end;
        vector<Node> nodes(V, { -1, -1 });
        
        bfs(start, end, graph, nodes);
        
        printResults(i + 1, start, end, nodes);
        cout << "--------" << endl;
    }

    return 0;
}
