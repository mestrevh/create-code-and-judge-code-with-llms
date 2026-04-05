/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line1, line2;
    if (!getline(cin, line1)) return 0;
    if (!getline(cin, line2)) line2 = "";

    vector<int> v1;
    stringstream ss1(line1);
    int val;
    while (ss1 >> val) {
        v1.push_back(val);
    }

    unordered_set<int> s2;
    stringstream ss2(line2);
    while (ss2 >> val) {
        s2.insert(val);
    }

    vector<int> missing;
    for (int x : v1) {
        if (s2.find(x) == s2.end()) {
            missing.push_back(x);
        }
    }

    if (missing.empty()) {
        return 0;
    }

    sort(missing.begin(), missing.end(), greater<int>());
    missing.erase(unique(missing.begin(), missing.end()), missing.end());

    for (int i = 0; i < (int)missing.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << missing[i];
    }
    cout << endl;

    return 0;
}