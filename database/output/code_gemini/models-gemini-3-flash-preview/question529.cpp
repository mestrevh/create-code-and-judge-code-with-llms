/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int Q, P;
        if (!(cin >> Q >> P)) break;

        vector<vector<int>> stacks(P);
        for (int i = 0; i < P; ++i) {
            int S;
            if (!(cin >> S)) break;
            stacks[i].resize(S);
            for (int j = 0; j < S; ++j) {
                cin >> stacks[i][j];
            }
        }

        queue<int> wash_queue;
        for (int q = 0; q < Q; ++q) {
            int type;
            if (!(cin >> type)) break;
            if (type == 1) {
                int x;
                cin >> x;
                bool found = false;
                for (int i = 0; i < P; ++i) {
                    if (!stacks[i].empty()) {
                        int y = stacks[i].back();
                        if (y >= x - 1 && y <= x + 1) {
                            wash_queue.push(y);
                            stacks[i].pop_back();
                            found = true;
                            break;
                        }
                    }
                }
                if (!found) {
                    cout << "ze nao vai pra festa " << x << "\n";
                }
            } else if (type == 2) {
                if (wash_queue.empty()) {
                    cout << "nao tem roupa pra lavar\n";
                } else {
                    cout << wash_queue.front() << "\n";
                    wash_queue.pop();
                }
            }
        }
    }

    return 0;
}