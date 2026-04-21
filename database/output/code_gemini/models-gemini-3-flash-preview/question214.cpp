/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    long long prefix_sum = 0;
    for (int i = 0; i < n; ++i) {
        prefix_sum += a[i];
        if (prefix_sum * 2 == total_sum) {
            cout << (i + 1) << endl;
            break;
        }
    }

    return 0;
}

