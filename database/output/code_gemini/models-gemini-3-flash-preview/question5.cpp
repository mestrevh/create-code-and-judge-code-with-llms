/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> q1(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> q1[i])) break;
    }

    vector<int> q2(m);
    for (int i = 0; i < m; ++i) {
        if (!(cin >> q2[i])) break;
    }

    if (k == 1) {
        // Queue 1 goes to lunch, Queue 2 is working
        int i = 0; // index for working queue (q2)
        int j = 0; // index for lunch queue (q1)
        while (i < m || j < n) {
            if (i < m) {
                cout << q2[i++] << "\n";
            }
            if (j < n) {
                cout << q1[j++] << "\n";
            }
        }
    } else if (k == 2) {
        // Queue 2 goes to lunch, Queue 1 is working
        int i = 0; // index for working queue (q1)
        int j = 0; // index for lunch queue (q2)
        while (i < n || j < m) {
            if (i < n) {
                cout << q1[i++] << "\n";
            }
            if (j < m) {
                cout << q2[j++] << "\n";
            }
        }
    }

    return 0;
}