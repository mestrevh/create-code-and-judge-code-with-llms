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

    int n1, n2;
    if (!(cin >> n1 >> n2)) return 0;

    vector<int> l1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> l1[i];
    }

    vector<int> l2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> l2[i];
    }

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (l1[i] <= l2[j]) {
            cout << l1[i++] << "\n";
        } else {
            cout << l2[j++] << "\n";
        }
    }

    while (i < n1) {
        cout << l1[i++] << "\n";
    }

    while (j < n2) {
        cout << l2[j++] << "\n";
    }

    return 0;
}