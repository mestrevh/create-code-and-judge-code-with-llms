/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int vago = 42 - n;
        if (vago < 0) vago = 0;
        double ganho = (double)vago * 1.75;
        cout << fixed << setprecision(2) << ganho << endl;
    }

    return 0;
}