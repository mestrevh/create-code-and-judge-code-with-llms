/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int b, t;
    if (!(cin >> b >> t)) return 0;

    int area_felix = (b + t) * 35;
    int area_total = 160 * 70;
    int area_marzia = area_total - area_felix;

    if (area_felix > area_marzia) {
        cout << 1 << endl;
    } else if (area_marzia > area_felix) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}