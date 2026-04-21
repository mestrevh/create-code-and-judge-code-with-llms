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
    if (!(cin >> n)) return 0;

    long long total = 0;
    long long coelhos = 0;
    long long ratos = 0;
    long long sapos = 0;

    for (int i = 0; i < n; ++i) {
        int quantia;
        char tipo;
        if (cin >> quantia >> tipo) {
            total += quantia;
            if (tipo == 'C') {
                coelhos += quantia;
            } else if (tipo == 'R') {
                ratos += quantia;
            } else if (tipo == 'S') {
                sapos += quantia;
            }
        }
    }

    cout << "Total: " << total << " cobaias" << "\n";
    cout << "Total de coelhos: " << coelhos << "\n";
    cout << "Total de ratos: " << ratos << "\n";
    cout << "Total de sapos: " << sapos << "\n";

    cout << fixed << setprecision(2);
    if (total > 0) {
        cout << "Percentual de coelhos: " << (double)coelhos * 100.0 / total << " %" << "\n";
        cout << "Percentual de ratos: " << (double)ratos * 100.0 / total << " %" << "\n";
        cout << "Percentual de sapos: " << (double)sapos * 100.0 / total << " %" << "\n";
    } else {
        cout << "Percentual de coelhos: 0.00 %" << "\n";
        cout << "Percentual de ratos: 0.00 %" << "\n";
        cout << "Percentual de sapos: 0.00 %" << "\n";
    }

    return 0;
}