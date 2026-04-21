/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, m1, h2, m2;
    if (!(cin >> h1 >> m1 >> h2 >> m2)) return 0;

    int total_minutes = m1 + m2;
    int carry_hours = total_minutes / 60;
    int final_minutes = total_minutes % 60;
    int final_hours = (h1 + h2 + carry_hours) % 24;

    cout << "Terminarei meu treino por volta das " << final_hours << " horas e " << final_minutes << " minutos!" << endl;

    return 0;
}