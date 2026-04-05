/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double dinheiro;
    if (!(cin >> dinheiro)) return 0;

    int b1, b2;
    cin >> b1 >> b2;

    double p1, p2;
    cin >> p1 >> p2;

    double divida;
    cin >> divida;

    double desconto = 0.0;
    if (b1 == 1 && b2 == 1) desconto = 0.12 * max(p1, p2);

    double menorConserto = 0.0;
    double maiorConserto = 0.0;

    if (b1 == 1 && b2 == 1) {
        menorConserto = p1 + p2;
        maiorConserto = max(p1, p2) - desconto + min(p1, p2);
        (void)menorConserto;
        double totalConserto = p1 + p2;
        double totalDividaComDesconto = divida - desconto;
        if (dinheiro >= totalDividaComDesconto && dinheiro >= totalConserto + totalDividaComDesconto - divida) {
            cout << "Sherliro livre do Jabbavitz e podendo voar\n";
        } else if (dinheiro >= totalConserto) {
            double falta = max(0.0, totalDividaComDesconto - (dinheiro - totalConserto));
            cout << "Sherliro consertou mas ta lascado com o Jabbavitz\n";
            cout << fixed << setprecision(2) << "faltam " << falta << " Napoleocoins\n";
        } else {
            double faltaDivida = max(0.0, totalDividaComDesconto - dinheiro);
            double faltaConserto = max(0.0, totalConserto - dinheiro);
            double faltaTotal = max(faltaDivida, 0.0) + max(faltaConserto, 0.0);
            cout << "Sherliro vai ser perseguido hoje e ainda ta sem nave\n";
            cout << fixed << setprecision(2) << "faltam " << (faltaDivida + (totalConserto - min(dinheiro, totalConserto))) << " Napoleocoins\n";
        }
        return 0;
    }

    double custoConserto = 0.0;
    if (b1 == 1) custoConserto += p1;
    if (b2 == 1) custoConserto += p2;

    bool podePagarDivida = (dinheiro >= divida);
    bool podeConsertar = (dinheiro >= custoConserto);

    if (podePagarDivida && podeConsertar) {
        cout << "Sherliro livre do Jabbavitz e podendo voar\n";
        return 0;
    }

    if (podeConsertar) {
        double sobraAposConserto = dinheiro - custoConserto;
        double falta = max(0.0, divida - sobraAposConserto);
        cout << "Sherliro consertou mas ta lascado com o Jabbavitz\n";
        cout << fixed << setprecision(2) << "faltam " << falta << " Napoleocoins\n";
        return 0;
    }

    double faltaTotal = max(0.0, divida + custoConserto - dinheiro);
    cout << "Sherliro vai ser perseguido hoje e ainda ta sem nave\n";
    cout << fixed << setprecision(2) << "faltam " << faltaTotal << " Napoleocoins\n";
    return 0;
}