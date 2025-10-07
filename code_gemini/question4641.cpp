/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
  int h1, m1, h2, m2;
  cin >> h1 >> m1 >> h2 >> m2;

  int total_minutes = m1 + m2;
  int final_minutes = total_minutes % 60;
  int carry_hours = total_minutes / 60;

  int total_hours = h1 + h2 + carry_hours;
  int final_hours = total_hours % 24;

  cout << "Terminarei meu treino por volta das " << final_hours << " horas e " << final_minutes << " minutos!" << endl;

  return 0;
}
`