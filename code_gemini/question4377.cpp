/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    char k;
    cin >> n >> k;

    if (k == 'I' || k == 'T') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i * 2; ++j) {
                cout << " ";
            }
            for (int j = 0; j < (n - i) * 2 - 1; ++j) {
                cout << "* ";
            }
            cout << endl;
        }
    }

    if (k == 'S' || k == 'T') {
        if (k == 'T') {
            cout << endl;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < i * 2; ++j) {
                cout << " ";
            }
            for (int j = 0; j < (n - i) * 2 - 1; ++j) {
                cout << "* ";
            }
            cout << endl;
        }
    }

    return 0;
}
