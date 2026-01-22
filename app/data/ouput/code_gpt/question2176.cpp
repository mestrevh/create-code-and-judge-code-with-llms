/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double preco_galao_eua, preco_litro_brasil, cotacao_dolar;
    cin >> preco_galao_eua >> preco_litro_brasil >> cotacao_dolar;

    double preco_litro_eua = (preco_galao_eua / 3.8) * cotacao_dolar;

    cout << fixed << setprecision(2);
    cout << "Gasolina EUA: R$ " << preco_litro_eua << endl;
    cout << "Gasolina Brasil: R$ " << preco_litro_brasil << endl;

    if (preco_litro_eua < preco_litro_brasil) {
        cout << "Mais barata nos EUA" << endl;
    } else if (preco_litro_eua > preco_litro_brasil) {
        cout << "Mais barata no Brasil" << endl;
    } else {
        cout << "Igual" << endl;
    }

    return 0;
}
