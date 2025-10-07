/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

void converter_moeda(double reais) {
    double dolares = reais / 5.75;
    cout << fixed << setprecision(2);
    cout << "A cotação de R$" << reais << " para dólar é US$" << dolares << endl;
}

int main() {
    double reais;
    cin >> reais;
    converter_moeda(reais);
    return 0;
}
