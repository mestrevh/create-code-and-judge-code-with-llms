/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    if (!(cin >> n >> i)) return 0;

    vector<int> v(n);
    for (int j = 0; j < n; ++j) {
        cin >> v[j];
    }

    if (i < 1 || i > n) return 0;

    nth_element(v.begin(), v.begin() + i - 1, v.end(), greater<int>());

    cout << v[i - 1] << endl;

    return 0;
}