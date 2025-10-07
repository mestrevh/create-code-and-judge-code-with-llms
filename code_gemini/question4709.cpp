/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void amadoProfessor(int n) {
  for (int i = 1; i <= 10; i++) {
    cout << n << " x " << i << " =  " << n * i << endl;
  }
}

int main() {
  int n;
  cin >> n;
  amadoProfessor(n);
  return 0;
}
