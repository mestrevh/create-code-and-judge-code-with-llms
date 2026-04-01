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

    int startInMinutes = h1 * 60 + m1;
    int endInMinutes = h2 * 60 + m2;

    int durationInMinutes = endInMinutes - startInMinutes;

    if (durationInMinutes <= 0) {
        durationInMinutes += 24 * 60;
    }

    int durationHours = durationInMinutes / 60;
    int durationMinutes = durationInMinutes % 60;

    cout << "O JOGO DUROU " << durationHours << " HORA(S) E " << durationMinutes << " MINUTO(S)" << endl;

    return 0;
}