/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char x, y;
    set<char> setA = {'a', 'b', 'c'};
    set<char> setB = {'d', 'e', 'f'};
    set<char> mappings[256];
    int valid_pair_count = 0;

    for (int i = 0; i < 3; ++i) {
        if (!(cin >> x >> y)) break;
        if (setA.count(x) && setB.count(y)) {
            mappings[(unsigned char)x].insert(y);
            valid_pair_count++;
        }
    }

    if (valid_pair_count == 0) {
        cout << "A ^ B void" << endl;
    } else {
        bool is_relation = false;
        int mapped_elements_from_A = 0;

        for (char c : setA) {
            if (mappings[(unsigned char)c].size() > 1) {
                is_relation = true;
            }
            if (!mappings[(unsigned char)c].empty()) {
                mapped_elements_from_A++;
            }
        }

        if (is_relation) {
            cout << "A <-> B" << endl;
        } else if (mapped_elements_from_A == 3) {
            cout << "A --> B" << endl;
        } else {
            cout << "A +-> B" << endl;
        }
    }

    return 0;
}