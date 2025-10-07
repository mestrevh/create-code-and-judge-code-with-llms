/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n, n2;
    cin >> n;
    vector<int> v1(n), v2;
    unordered_map<int, int> count;

    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
        count[v1[i]]++;
    }
    
    cin >> n2;
    v2.resize(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> v2[i];
        count[v2[i]]++;
    }

    vector<int> repeated, unique, without_repeated;
    for (const auto& p : count) {
        if (p.second > 1) {
            repeated.push_back(p.first);
        }
        unique.push_back(p.first);
    }

    sort(repeated.begin(), repeated.end());
    sort(unique.begin(), unique.end());

    for (const auto& num : unique) {
        if (find(repeated.begin(), repeated.end(), num) == repeated.end()) {
            without_repeated.push_back(num);
        }
    }

    cout << "[";
    for (size_t i = 0; i < repeated.size(); ++i) {
        cout << repeated[i] << (i < repeated.size() - 1 ? ", " : "");
    }
    cout << "]\n";

    cout << "[";
    for (size_t i = 0; i < unique.size(); ++i) {
        cout << unique[i] << (i < unique.size() - 1 ? ", " : "");
    }
    cout << "]\n";

    cout << "[";
    for (size_t i = 0; i < without_repeated.size(); ++i) {
        cout << without_repeated[i] << (i < without_repeated.size() - 1 ? ", " : "");
    }
    cout << "]\n";

    return 0;
}
