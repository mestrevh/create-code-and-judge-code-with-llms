/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int x;
  cin >> x;

  double y = (5 * pow(x, 3)) - (4 * pow(x, 2)) + (9 * x) - 1;

  cout << fixed << setprecision(1) << "Y= " << y << endl;

  return 0;
}
