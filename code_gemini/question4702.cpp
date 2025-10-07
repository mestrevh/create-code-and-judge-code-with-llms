/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

string par_ou_impar(int n) {
  if (n % 2 == 0) {
    return "Par";
  } else {
    return "Ímpar";
  }
}

int main() {
  int n;
  cin >> n;
  cout << par_ou_impar(n) << endl;
  return 0;
}
