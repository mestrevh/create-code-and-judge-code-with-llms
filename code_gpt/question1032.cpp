/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int hole, vector<int>& holes, vector<bool>& visited) {
    visited[hole] = true;
    int next_hole = holes[hole];
    if (!visited[next_hole]) {
        dfs(next_hole, holes, visited);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> holes(N);
    for (int i = 0; i < N; i++) {
        cin >> holes[i];
    }
    
    vector<bool> visited(N, false);
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, holes, visited);
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
