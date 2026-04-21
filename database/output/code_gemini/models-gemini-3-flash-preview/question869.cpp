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

    int Q;
    if (!(cin >> Q)) return 0;

    if (Q <= 0) {
        return 0;
    }

    vector<int> v(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> v[i];
    }

    if (Q == 1) {
        cout << 1 << endl;
        return 0;
    }

    int max_len = 1;
    int current_len = 1;

    // A carousel is circular. To check all continuous sequences including those
    // that wrap around, we can iterate up to 2*Q-1 elements.
    for (int i = 0; i < 2 * Q - 1; ++i) {
        if (v[i % Q] < v[(i + 1) % Q]) {
            current_len++;
            if (current_len >= Q) {
                max_len = Q;
                break;
            }
        } else {
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 1;
        }
    }

    if (current_len > max_len) {
        max_len = current_len;
    }

    cout << max_len << endl;

    return 0;
}