/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int min_envelopes = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        int count;
        if (cin >> count) {
            if (count < min_envelopes) {
                min_envelopes = count;
            }
        }
    }

    if (n > 0) {
        cout << min_envelopes << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}