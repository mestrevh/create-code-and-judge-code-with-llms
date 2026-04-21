/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int o;
    if (!(cin >> o)) return 0;

    int n;
    cin >> n;
    vector<int> p1(n);
    for (int i = 0; i < n; ++i) {
        cin >> p1[i];
    }
    sort(p1.begin(), p1.end());

    int m;
    cin >> m;
    vector<int> p2(m);
    for (int i = 0; i < m; ++i) {
        cin >> p2[i];
    }
    sort(p2.begin(), p2.end());

    vector<int> result;

    if (o == 1) {
        set_union(p1.begin(), p1.end(), p2.begin(), p2.end(), back_inserter(result));
    } else if (o == 2) {
        set_intersection(p1.begin(), p1.end(), p2.begin(), p2.end(), back_inserter(result));
    }

    if (result.empty()) {
        cout << "empty" << endl;
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}