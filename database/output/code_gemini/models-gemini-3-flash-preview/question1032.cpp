/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }

    vector<bool> visited(N, false);
    int tocas = 0;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            tocas++;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = p[current];
            }
        }
    }

    cout << tocas << endl;

    return 0;
}
