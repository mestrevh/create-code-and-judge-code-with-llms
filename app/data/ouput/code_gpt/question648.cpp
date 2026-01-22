/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int N, P;
    while (cin >> N >> P, N || P) {
        vector<deque<int>> stacks(P);
        vector<bool> exists(N + 1, false);
        int boxCount = 0;

        for (int i = 0; i < P; i++) {
            int Q;
            cin >> Q;
            for (int j = 0; j < Q; j++) {
                int box;
                cin >> box;
                stacks[i].push_back(box);
                exists[box] = true;
            }
        }

        vector<int> order(N + 1, -1);
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < stacks[i].size(); j++) {
                order[stacks[i][j]] = i;
            }
        }

        vector<bool> seen(N + 1, false);
        seen[1] = true;

        for (int i = 2; i <= N; i++) {
            if (!seen[i]) {
                boxCount++;
                int currentBox = i;
                while (currentBox != -1) {
                    seen[currentBox] = true;
                    int stackIndex = order[currentBox];
                    if (stackIndex != -1) {
                        while (!stacks[stackIndex].empty() && stacks[stackIndex].back() != currentBox) {
                            currentBox = stacks[stackIndex].back();
                            stacks[stackIndex].pop_back();
                            seen[currentBox] = true;
                        }
                        if (!stacks[stackIndex].empty()) {
                            currentBox = stacks[stackIndex].back();
                            stacks[stackIndex].pop_back();
                        } else {
                            currentBox = -1;
                        }
                    } else {
                        currentBox = -1;
                    }
                }
            }
        }
        cout << boxCount << endl;
    }
    return 0;
}
