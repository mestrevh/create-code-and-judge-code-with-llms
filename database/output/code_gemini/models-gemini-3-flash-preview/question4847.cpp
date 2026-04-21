/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;

    int cur_x = 0;
    bool first = true;

    for (int i = 0; i < q; ++i) {
        int x;
        char c;
        if (!(cin >> x >> c)) break;

        if (c == 'D') {
            if (first) {
                for (int j = 0; j < x; ++j) {
                    cout << ".";
                }
                cur_x = x - 1;
                first = false;
            } else {
                cout << "\n";
                for (int j = 0; j < cur_x; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < x; ++j) {
                    cout << ".";
                }
                cur_x = cur_x + x - 1;
            }
        } else if (c == 'E') {
            if (first) {
                if (x > 1) {
                    cout << "Informacao invalida" << endl;
                    return 0;
                }
                cout << ".";
                cur_x = 0;
                first = false;
            } else {
                if (cur_x - x + 1 < 0) {
                    cout << "Informacao invalida" << endl;
                    return 0;
                }
                cout << "\n";
                for (int j = 0; j < cur_x - x + 1; ++j) {
                    cout << " ";
                }
                for (int j = 0; j < x; ++j) {
                    cout << ".";
                }
                cur_x = cur_x - x + 1;
            }
        } else if (c == 'B') {
            if (first) {
                if (x > 0) {
                    cout << ".";
                    for (int j = 0; j < x - 1; ++j) {
                        cout << "\n.";
                    }
                }
                cur_x = 0;
                first = false;
            } else {
                for (int j = 0; j < x; ++j) {
                    cout << "\n";
                    for (int k = 0; k < cur_x; ++k) {
                        cout << " ";
                    }
                    cout << ".";
                }
            }
        }
    }
    cout << endl;

    return 0;
}