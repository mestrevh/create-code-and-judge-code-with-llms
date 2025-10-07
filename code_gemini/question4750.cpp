/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int min_diff = 1e9;

  min_diff = min(min_diff, abs((a + b) - (c + d)));
  min_diff = min(min_diff, abs((a + c) - (b + d)));
  min_diff = min(min_diff, abs((a + d) - (b + c)));

  cout << min_diff << endl;

  return 0;
}
