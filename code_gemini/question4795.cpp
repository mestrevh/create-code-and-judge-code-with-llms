/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double a, b;
  cin >> a >> b;

  double media1 = (a + b) / 2.0;
  double media2 = (media1 + a) / 2.0;
  double media3 = (media2 + a) / 2.0;

  cout << fixed << setprecision(2) << media3 << endl;

  return 0;
}
