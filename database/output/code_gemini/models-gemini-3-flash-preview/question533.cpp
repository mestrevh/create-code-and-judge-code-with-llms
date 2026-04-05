/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

class HashSet {
public:
    int m;
    int n;
    vector<list<int>> table;
    vector<int> list_sizes;
    vector<int> size_counts;
    int max_l;

    HashSet() : m(7), n(0), table(7), list_sizes(7, 0), size_counts(1, 7), max_l(0) {
        size_counts[0] = 7;
    }

    void add(int k, int op_idx) {
        int idx = k % m;
        int comparisons = 0;
        bool found = false;
        for (int val : table[idx]) {
            comparisons++;
            if (val == k) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << op_idx << " 0 " << comparisons << "\n";
        } else {
            cout << op_idx << " 1 " << comparisons << "\n";
            table[idx].push_front(k);
            
            int old_s = list_sizes[idx];
            list_sizes[idx]++;
            int new_s = list_sizes[idx];
            size_counts[old_s]--;
            if (new_s >= (int)size_counts.size()) size_counts.resize(new_s + 1, 0);
            size_counts[new_s]++;
            if (new_s > max_l) max_l = new_s;
            
            n++;
            if (4LL * n >= 3LL * m) {
                rehash();
            }
        }
    }

    void del(int k, int op_idx) {
        int idx = k % m;
        int comparisons = 0;
        auto it_to_erase = table[idx].end();
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            comparisons++;
            if (*it == k) {
                it_to_erase = it;
                break;
            }
        }

        if (it_to_erase != table[idx].end()) {
            table[idx].erase(it_to_erase);
            
            int old_s = list_sizes[idx];
            list_sizes[idx]--;
            int new_s = list_sizes[idx];
            size_counts[old_s]--;
            size_counts[new_s]++;
            if (old_s == max_l && size_counts[old_s] == 0) {
                while (max_l > 0 && size_counts[max_l] == 0) max_l--;
            }
            
            n--;
            cout << op_idx << " 1 " << comparisons << "\n";
        } else {
            cout << op_idx << " 0 " << comparisons << "\n";
        }
    }

    void has(int k, int op_idx) {
        int idx = k % m;
        int comparisons = 0;
        bool found = false;
        for (int val : table[idx]) {
            comparisons++;
            if (val == k) {
                found = true;
                break;
            }
        }
        cout << op_idx << (found ? " 1 " : " 0 ") << comparisons << "\n";
    }

    void prt(int op_idx) {
        cout << op_idx << " " << m << " " << n << " " << max_l << "\n";
    }

    void rehash() {
        int old_m = m;
        m = 2 * m - 1;
        vector<list<int>> old_table = std::move(table);
        
        table.assign(m, list<int>());
        list_sizes.assign(m, 0);
        size_counts.assign(n + 1, 0);
        size_counts[0] = m;
        max_l = 0;

        for (int i = 0; i < old_m; i++) {
            for (int val : old_table[i]) {
                int idx_new = val % m;
                table[idx_new].push_front(val);
                
                int old_s = list_sizes[idx_new];
                list_sizes[idx_new]++;
                int new_s = list_sizes[idx_new];
                size_counts[old_s]--;
                if (new_s >= (int)size_counts.size()) size_counts.resize(new_s + 1, 0);
                size_counts[new_s]++;
                if (new_s > max_l) max_l = new_s;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    HashSet s;
    string cmd;
    int op_idx = 0;
    while (cin >> cmd) {
        if (cmd == "ADD") {
            int k; cin >> k;
            s.add(k, op_idx);
        } else if (cmd == "DEL") {
            int k; cin >> k;
            s.del(k, op_idx);
        } else if (cmd == "HAS") {
            int k; cin >> k;
            s.has(k, op_idx);
        } else if (cmd == "PRT") {
            s.prt(op_idx);
        }
        op_idx++;
    }
    return 0;
}