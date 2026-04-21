/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double pol_index;
    if (!(cin >> pol_index)) return 0;

    if (pol_index > 0.4) {
        cout << "Grupo 1" << "\n";
        cout << "Grupo 2" << "\n";
        cout << "Grupo 3" << "\n";
    } else if (pol_index > 0.3) {
        cout << "Grupo 1" << "\n";
        cout << "Grupo 2" << "\n";
    } else if (pol_index > 0.25) {
        cout << "Grupo 1" << "\n";
    }

    return 0;
}