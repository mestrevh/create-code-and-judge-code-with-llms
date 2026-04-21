/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n == 0) {
        cout << "Sem negociacoes por hoje!" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        string buyer, country, continent;
        int code;
        int quantity;

        if (!(cin >> ws)) break;
        if (!getline(cin, buyer)) break;
        if (!getline(cin, country)) break;
        if (!getline(cin, continent)) break;
        if (!(cin >> code >> quantity)) break;

        string product = "";
        double priceBRL = 0;
        bool valid = true;

        if (code == 101) { product = "Abacaxi"; priceBRL = 73.00; }
        else if (code == 202) { product = "Banana"; priceBRL = 30.00; }
        else if (code == 303) { product = "Cafe"; priceBRL = 350.00; }
        else if (code == 404) { product = "Caju"; priceBRL = 110.00; }
        else if (code == 505) { product = "Melancia"; priceBRL = 50.00; }
        else if (code == 606) { product = "Soja"; priceBRL = 170.00; }
        else if (code == 702) { product = "Laranja"; priceBRL = 179.53; }
        else if (code == 808) { product = "Trigo"; priceBRL = 130.00; }
        else if (code == 909) { product = "Carne Bovina"; priceBRL = 420.00; }
        else if (code == 1010) { product = "Carne Suina"; priceBRL = 310.00; }
        else valid = false;

        if (!valid) {
            cout << "Operacao invalida!" << endl;
            continue;
        }

        double freight = 0;
        if (continent == "America") freight = 150.00;
        else if (continent == "Europa") freight = 220.00;
        else if (continent == "Asia") freight = 280.00;
        else if (continent == "Oceania") freight = 350.00;
        else if (continent == "Africa") freight = 200.00;

        double productCostUSD = (priceBRL * (double)quantity) / 5.17;
        double total = productCostUSD + freight;

        cout << buyer << "\n";
        cout << country << "\n";
        cout << product << "\n";
        cout << fixed << setprecision(2);
        cout << "Valor do produto: U$ " << productCostUSD << "\n";
        cout << "Valor do frete: U$ " << freight << "\n";
        cout << "Valor total: U$ " << total << endl;
    }

    return 0;
}