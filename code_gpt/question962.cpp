/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                cout << j + 1;
            } else {
                cout << i + 1;
            }
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
