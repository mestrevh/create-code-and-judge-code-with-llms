/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

void converter_moeda(double reais) {
    double cotacao = 5.75;
    double dolares = reais / cotacao;
    cout << fixed << setprecision(2);
    cout << "A cotação de R$" << reais << " para dólar é US$" << dolares << endl;
}

int main() {
    double reais;
    cin >> reais;
    converter_moeda(reais);
    return 0;
}
