/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int n;
  double a;
  cin >> n >> a;

  cout << fixed << setprecision(2);

  if (n == 1) {
    cout << pow(a, 2) << endl;
  } else if (n == 2) {
    cout << sqrt(a) << endl;
  } else if (n == 3) {
    cout << abs(a) << endl;
  } else if (n == 4) {
    cout << log2(a) << endl;
  }

  return 0;
}
