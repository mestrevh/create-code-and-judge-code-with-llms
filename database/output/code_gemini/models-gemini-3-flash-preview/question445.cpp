/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long dias, km_total;
    if (!(cin >> dias >> km_total)) return 0;

    double custo_fixo = dias * 90.0;
    long long cota_total = dias * 100;
    long long km_extra = max(0LL, km_total - cota_total);
    double custo_extra = km_extra * 12.0;

    double total = custo_fixo + custo_extra;

    cout << fixed << setprecision(2) << total << endl;

    return 0;
}