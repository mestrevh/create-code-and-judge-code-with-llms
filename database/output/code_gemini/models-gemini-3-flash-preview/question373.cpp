/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[4];
    if (!(cin >> a[0] >> a[1] >> a[2] >> a[3])) return 0;
    sort(a, a + 4);
    if (a[0] * a[3] == a[1] * a[2]) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}