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

    double ipva, taxa;
    if (cin >> ipva >> taxa) {
        double ipva_com_desconto = ipva * 0.95;
        double total = ipva_com_desconto + taxa;

        cout << fixed << setprecision(2) << total << endl;
    }

    return 0;
}