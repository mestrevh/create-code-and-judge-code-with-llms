/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n < 1) return 0;

    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    do {
        for (int i = 0; i < n; ++i) {
            cout << v[i];
        }
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}