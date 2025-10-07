/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  unordered_map<char, char> m = {
    {'0', 'o'},
    {'1', 'i'},
    {'3', 'e'},
    {'4', 'a'},
    {'5', 's'}
  };

  for (char& c : s) {
    if (m.count(c)) {
      c = m[c];
    }
  }

  cout << s << endl;

  return 0;
}
