/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> result;
    unordered_set<int> seen;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (seen.find(val) == seen.end()) {
            seen.insert(val);
            result.push_back(val);
        }
    }

    int n2;
    if (!(cin >> n2)) {
        // Handle potential lack of n2 if input ends early
    } else {
        for (int i = 0; i < n2; ++i) {
            int val;
            cin >> val;
            if (seen.find(val) == seen.end()) {
                seen.insert(val);
                result.push_back(val);
            }
        }
    }

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}