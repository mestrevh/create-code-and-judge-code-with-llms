/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

static vector<int> key_to_values[32768];
static set<pair<int, int>> coordinate_sets[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    string op;
    int op_idx = 0;
    while (cin >> op && op != "END") {
        if (op == "ADD") {
            int k;
            cin >> k;
            key_to_values[k].resize(N);
            for (int j = 0; j < N; ++j) {
                cin >> key_to_values[k][j];
                coordinate_sets[j].insert({key_to_values[k][j], k});
            }
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (!coordinate_sets[j].empty() && coordinate_sets[j].rbegin()->second == k) {
                    cnt++;
                }
            }
            cout << op_idx << " " << cnt << "\n";
        } else if (op == "UPD") {
            int k;
            cin >> k;
            vector<int> old_v = key_to_values[k];
            for (int j = 0; j < N; ++j) {
                int new_val;
                cin >> new_val;
                coordinate_sets[j].erase({old_v[j], k});
                coordinate_sets[j].insert({new_val, k});
                key_to_values[k][j] = new_val;
            }
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (!coordinate_sets[j].empty() && coordinate_sets[j].rbegin()->second == k) {
                    cnt++;
                }
            }
            cout << op_idx << " " << cnt << "\n";
        } else if (op == "MAX") {
            int j_target;
            cin >> j_target;
            if (!coordinate_sets[j_target].empty()) {
                int k = coordinate_sets[j_target].rbegin()->second;
                cout << op_idx << " " << k;
                vector<int> v = key_to_values[k];
                for (int j = 0; j < N; ++j) {
                    cout << " " << v[j];
                    coordinate_sets[j].erase({v[j], k});
                }
                cout << "\n";
            }
        }
        op_idx++;
    }

    return 0;
}