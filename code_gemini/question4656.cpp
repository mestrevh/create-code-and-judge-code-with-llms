/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;

  string even = "";
  string odd = "";

  for (int i = 0; i < s.length(); i++) {
    if (i % 2 == 0) {
      even += s[i];
    } else {
      odd += s[i];
    }
  }

  reverse(s.begin(), s.end());

  cout << "Somente posições pares: " << even << endl;
  cout << "Somente posições ímpares: " << odd << endl;
  cout << "De trás para frente: " << s << endl;

  return 0;
}
