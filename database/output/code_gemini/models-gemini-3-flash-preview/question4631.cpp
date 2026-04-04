/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    map<int, int> counts;

    if (cin >> n) {
        for (int i = 0; i < n; ++i) {
            int val;
            if (cin >> val) {
                counts[val]++;
            }
        }
    }

    int n2;
    if (cin >> n2) {
        for (int i = 0; i < n2; ++i) {
            int val;
            if (cin >> val) {
                counts[val]++;
            }
        }
    }

    vector<int> repeated;
    vector<int> all_unique;
    vector<int> non_repeated;

    for (auto const& entry : counts) {
        int val = entry.first;
        int count = entry.second;
        
        all_unique.push_back(val);
        if (count > 1) {
            repeated.push_back(val);
        } else {
            non_repeated.push_back(val);
        }
    }

    auto printVec = [](const vector<int>& v) {
        cout << "[";
        for (size_t i = 0; i < v.size(); ++i) {
            cout << v[i];
            if (i < v.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    };

    printVec(repeated);
    printVec(all_unique);
    printVec(non_repeated);

    return 0;
}