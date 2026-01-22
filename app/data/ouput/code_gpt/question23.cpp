/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool first = true;
    for (int i = (n % 5 == 0 ? n : n + (5 - n % 5)); i <= m; i += 5) {
        if (!first) cout << "|";
        cout << i;
        first = false;
    }
    cout << endl;
    return 0;
}
