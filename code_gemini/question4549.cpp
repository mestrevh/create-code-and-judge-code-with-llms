/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double valor_fatura;
  cin >> valor_fatura;

  double valor_marco = valor_fatura * 0.5;
  double valor_abril = valor_marco * 1.065;

  cout << fixed << setprecision(2);
  cout << "Valor total da fatura: R$ " << valor_fatura << endl;
  cout << "Valor a pagar em Marco: R$ " << valor_marco << endl;
  cout << "Valor a pagar em Abril: R$ " << valor_abril << endl;

  return 0;
}
