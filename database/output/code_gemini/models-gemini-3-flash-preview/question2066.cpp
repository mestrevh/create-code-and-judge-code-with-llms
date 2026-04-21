/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long val;
        if (cin >> val) {
            sum += val;
        }
    }

    cout << sum << "\n";

    return 0;
}