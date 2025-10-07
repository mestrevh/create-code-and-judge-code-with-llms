/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double n1, n2, n3;
  cin >> n1 >> n2 >> n3;

  double media = (n1 + n2 + n3) / 3.0;

  if (media >= 6.0) {
    cout << "Aprovado" << endl;
  } else {
    cout << "Reprovado" << endl;
  }

  return 0;
}
