/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

string eh_bissexto(int ano) {
  if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 4 == 0 && ano % 100 == 0 && ano % 400 == 0)) {
    return "bissexto";
  } else {
    return "nao bissexto";
  }
}

int main() {
  int ano;
  cin >> ano;
  cout << eh_bissexto(ano) << endl;
  return 0;
}
