/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double nota;
  cin >> nota;

  cout << "Nota digitada: " << fixed << setprecision(1) << nota << endl;

  if (nota < 0 || nota > 10) {
    cout << "A nota nao esta no intervalo [0,10]" << endl;
  }

  return 0;
}
