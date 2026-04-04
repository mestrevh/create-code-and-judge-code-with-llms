/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int height, age;
    if (!(cin >> height >> age)) return 0;

    int count = 0;

    // Barca Viking: 1,5m (150cm) e 12 anos
    if (height >= 150 && age >= 12) {
        count++;
    }

    // Elevator of Death: 1,4m (140cm) e 14 anos
    if (height >= 140 && age >= 14) {
        count++;
    }

    // Final Killer: 1,7m (170cm) ou 16 anos
    if (height >= 170 || age >= 16) {
        count++;
    }

    cout << count << "\n";

    return 0;
}