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

    int paes, broas;
    if (cin >> paes >> broas) {
        double total = paes * 0.45 + broas * 2.25;
        double poupanca = total * 0.15;

        cout << fixed << setprecision(2);
        cout << total << "\n" << poupanca << "\n";
    }

    return 0;
}