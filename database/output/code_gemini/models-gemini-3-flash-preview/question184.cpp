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

    int a, l, p;
    if (!(cin >> a >> l >> p)) return 0;

    if (n <= a && n <= l && n <= p) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}