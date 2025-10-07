/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int latas350, garrafas600, garrafas2l;
  cin >> latas350 >> garrafas600 >> garrafas2l;

  double totalLitros = (latas350 * 0.35) + (garrafas600 * 0.6) + (garrafas2l * 2.0);

  cout << fixed << setprecision(1) << "Foram comprados " << totalLitros << " litros de refrigerante." << endl;

  return 0;
}
