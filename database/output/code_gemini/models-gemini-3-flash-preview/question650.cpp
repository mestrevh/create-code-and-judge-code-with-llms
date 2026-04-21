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
    while (cin >> n && n != 0) {
        long long total_pairs = 0;
        for (int i = 0; i < n; ++i) {
            int c, v;
            cin >> c >> v;
            total_pairs += (v / 2);
        }
        cout << (total_pairs / 2) << "\n";
    }

    return 0;
}