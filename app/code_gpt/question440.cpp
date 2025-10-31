/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m, n || m) {
        vector<vector<int>> groups(n);
        vector<bool> visited(n, false);
        queue<int> q;

        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int student;
                cin >> student;
                groups[student].push_back(i);
            }
        }

        q.push(0);
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int group : groups[current]) {
                for (int member : groups[group]) {
                    if (!visited[member]) {
                        visited[member] = true;
                        q.push(member);
                        count++;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
