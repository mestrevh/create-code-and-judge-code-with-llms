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

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a < 0 || b < 0 || c < 0) {
        cout << "ERRO" << endl;
        return 0;
    }

    bool is_odd = (a % 2 != 0);
    vector<long long> v = {a, b, c};

    if (is_odd) {
        sort(v.begin(), v.end());
    } else {
        sort(v.begin(), v.end(), greater<long long>());
    }

    for (int i = 0; i < 3; ++i) {
        cout << v[i] << "\n";
    }

    return 0;
}