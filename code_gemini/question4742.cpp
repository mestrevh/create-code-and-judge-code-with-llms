/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double nota1, nota2;
  cin >> nota1 >> nota2;
  cout << fixed << setprecision(1) << "Média= " << (nota1 * 6 + nota2 * 4) / 10 << endl;
  return 0;
}
