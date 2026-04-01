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

    bool is_upper = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            if (!(cin >> val)) break;
            if (i > j && val != 0) {
                is_upper = false;
            }
        }
    }

    if (is_upper) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}