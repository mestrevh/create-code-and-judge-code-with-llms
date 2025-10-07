/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  string s;

  cin >> n >> s;

  reverse(s.begin(), s.end());

  int i = 0;
  while (i < s.length() - 1 && s[i] == '0') {
    i++;
  }

  cout << s.substr(i) << endl;

  return 0;
}
