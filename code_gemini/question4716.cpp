/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
