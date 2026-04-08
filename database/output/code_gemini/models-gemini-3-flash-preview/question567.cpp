/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>

using namespace std;

struct Structure {
    list<int> elements;
    bool isStack;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    int caseNum = 0;
    while (cin >> cmd) {
        vector<Structure> v;
        v.push_back({list<int>(), false}); // Position 0, initially Queue

        while (cmd != "END") {
            if (cmd == "ADD") {
                int i, val;
                cin >> i >> val;
                if (i >= 0 && i < (int)v.size()) {
                    if (v[i].isStack) v[i].elements.push_front(val);
                    else v[i].elements.push_back(val);
                }
            } else if (cmd == "DEL") {
                int i;
                cin >> i;
                if (i >= 0 && i < (int)v.size() && !v[i].elements.empty()) {
                    v[i].elements.pop_front();
                }
            } else if (cmd == "SPL") {
                int i;
                cin >> i;
                if (i >= 0 && i < (int)v.size()) {
                    int n = v[i].elements.size();
                    int first_size = n / 2;
                    Structure next;
                    next.isStack = v[i].isStack;
                    if (n == 0) {
                        v[i].isStack = true;
                        next.isStack = true;
                    }
                    auto it = v[i].elements.begin();
                    advance(it, first_size);
                    next.elements.splice(next.elements.begin(), v[i].elements, it, v[i].elements.end());
                    v.insert(v.begin() + i + 1, next);
                }
            } else if (cmd == "MER") {
                int i, j;
                cin >> i >> j;
                if (i >= 0 && i < (int)v.size() && j >= 0 && j < (int)v.size() && i != j) {
                    list<int> tempElements = move(v[j].elements);
                    v.erase(v.begin() + j);
                    int target = (j < i ? i - 1 : i);
                    v[target].elements.splice(v[target].elements.end(), tempElements);
                }
            } else if (cmd == "TRA") {
                int i;
                cin >> i;
                if (i >= 0 && i < (int)v.size()) {
                    v[i].isStack = !v[i].isStack;
                }
            }
            if (!(cin >> cmd)) break;
        }

        cout << "caso " << caseNum++ << ":";
        for (size_t i = 0; i < v.size(); ++i) {
            if (v[i].elements.empty()) cout << " ?";
            else cout << " " << v[i].elements.front();
        }
        cout << "\n\n";
    }
    return 0;
}

