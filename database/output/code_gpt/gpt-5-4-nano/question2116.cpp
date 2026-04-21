/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string opcaoCarne;
    string alho, adultos, criancas;
    long long nCriancas, nAdultos;

    if (!(cin >> opcaoCarne)) return 0;
    if (!(cin >> alho)) return 0;
    if (!(cin >> adultos)) return 0;
    if (!(cin >> criancas)) return 0;
    if (!(cin >> nCriancas)) return 0;
    if (!(cin >> nAdultos)) return 0;

    auto invalid = [&]() {
        cout << "Opção inválida.";
        return 0;
    };

    if (opcaoCarne != "C" && opcaoCarne != "BF" && opcaoCarne != "BS") invalid();

    const double bovinaKg = 32.0, frangoKg = 18.0, suinaKg = 15.0;
    const double cerveja = 8.0, refri = 6.0;

    double carneBov = 0, carneFra = 0, carneSua = 0;

    if (opcaoCarne == "C") {
        carneBov = nAdultos * 0.2 + nCriancas * 0.2;
        carneFra = nAdultos * 0.1;
        carneSua = nAdultos * 0.1;
    } else if (opcaoCarne == "BF") {
        carneBov = nAdultos * 0.25 + nCriancas * 0.2;
        carneFra = nAdultos * 0.15;
        carneSua = 0;
    } else if (opcaoCarne == "BS") {
        carneBov = nAdultos * 0.25 + nCriancas * 0.2;
        carneFra = 0;
        carneSua = nAdultos * 0.15;
    }

    double total = carneBov * bovinaKg + carneFra * frangoKg + carneSua * suinaKg;

    if (alho == "S") total *= 0.98;

    if (adultos == "S") total += nAdultos * 2.0 * cerveja;
    if (criancas == "S") total += nCriancas * 0.5 * refri;

    cout << fixed << setprecision(2) << "R$: " << total;
    return 0;
}