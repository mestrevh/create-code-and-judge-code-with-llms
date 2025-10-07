/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string inverter_string(string str) {
  reverse(str.begin(), str.end());
  return str;
}

int main() {
  string input_string;
  getline(cin, input_string);
  cout << inverter_string(input_string) << endl;
  return 0;
}
