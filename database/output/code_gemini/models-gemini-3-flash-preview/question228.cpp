/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> blocks[25];
int pos[25];

void clear_above(int a) {
    int p = pos[a];
    while (blocks[p].back() != a) {
        int top = blocks[p].back();
        blocks[top].push_back(top);
        pos[top] = top;
        blocks[p].pop_back();
    }
}

void move_pile(int a, int b) {
    int pa = pos[a];
    int pb = pos[b];
    auto it = find(blocks[pa].begin(), blocks[pa].end(), a);
    vector<int> to_move;
    for (auto i = it; i != blocks[pa].end(); ++i) {
        to_move.push_back(*i);
        pos[*i] = pb;
    }
    blocks[pa].erase(it, blocks[pa].end());
    for (int x : to_move) {
        blocks[pb].push_back(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        blocks[i].push_back(i);
        pos[i] = i;
    }

    string cmd1, cmd2;
    int a, b;
    while (cin >> cmd1 && cmd1 != "final") {
        cin >> a >> cmd2 >> b;

        if (a == b || pos[a] == pos[b]) continue;

        if (cmd1 == "mover") {
            if (cmd2 == "sobre") {
                clear_above(a);
                clear_above(b);
                move_pile(a, b);
            } else if (cmd2 == "acima") {
                clear_above(a);
                move_pile(a, b);
            }
        } else if (cmd1 == "pilha") {
            if (cmd2 == "sobre") {
                clear_above(b);
                move_pile(a, b);
            } else if (cmd2 == "acima") {
                move_pile(a, b);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << i << ":";
        for (int val : blocks[i]) {
            cout << " " << val;
        }
        cout << "\n";
    }

    return 0;
}