/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        if (i % 2 != 0) {
            cout << i << endl;
        }
    }
    return 0;
}
