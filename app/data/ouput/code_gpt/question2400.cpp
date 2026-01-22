/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, quantia, total = 0, coelhos = 0, ratos = 0, sapos = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> quantia;
        char tipo;
        cin >> tipo;
        
        total += quantia;
        if (tipo == 'C') coelhos += quantia;
        else if (tipo == 'R') ratos += quantia;
        else if (tipo == 'S') sapos += quantia;
    }

    cout << "Total: " << total << " cobaias" << endl;
    cout << "Total de coelhos: " << coelhos << endl;
    cout << "Total de ratos: " << ratos << endl;
    cout << "Total de sapos: " << sapos << endl;
    cout << fixed << setprecision(2);
    cout << "Percentual de coelhos: " << (coelhos * 100.0 / total) << " %" << endl;
    cout << "Percentual de ratos: " << (ratos * 100.0 / total) << " %" << endl;
    cout << "Percentual de sapos: " << (sapos * 100.0 / total) << " %" << endl;

    return 0;
}
