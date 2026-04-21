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

    int n_ops;
    if (!(cin >> n_ops)) return 0;

    vector<vector<int>> stacks;
    int capacity = 0;
    bool first_output = true;

    for (int i = 0; i < n_ops; ++i) {
        char cmd;
        if (!(cin >> cmd)) break;
        
        if (cmd == 'c') {
            cin >> capacity;
            continue;
        } else if (cmd == 'i') {
            int val;
            cin >> val;
            if (stacks.empty() || (int)stacks.back().size() >= capacity) {
                stacks.push_back(vector<int>());
            }
            stacks.back().push_back(val);
        } else if (cmd == 'r') {
            if (!stacks.empty()) {
                stacks.back().pop_back();
                if (stacks.back().empty()) {
                    stacks.pop_back();
                }
            }
        }

        if (!first_output) cout << "\n";
        first_output = false;

        cout << "Conjunto de pilhas:\n";
        if (stacks.empty()) {
            cout << "conjunto de pilhas vazio!\n";
        } else {
            for (int i_s = (int)stacks.size() - 1; i_s >= 0; --i_s) {
                cout << "pilha:\n";
                for (int i_e = (int)stacks[i_s].size() - 1; i_e >= 0; --i_e) {
                    cout << stacks[i_s][i_e] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}