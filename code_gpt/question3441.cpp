/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "  ";
        }
        for (int j = i + 1; j <= n; ++j) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
