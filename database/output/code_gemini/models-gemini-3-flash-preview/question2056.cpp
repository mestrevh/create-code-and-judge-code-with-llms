/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> evens;
    vector<int> odds;
    evens.reserve(n);
    odds.reserve(n);

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 0) {
            evens.push_back(val);
        } else {
            odds.push_back(val);
        }
    }

    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end(), [](int a, int b) {
        return a > b;
    });

    for (const int& x : evens) {
        cout << x << "\n";
    }
    for (const int& x : odds) {
        cout << x << "\n";
    }

    return 0;
}