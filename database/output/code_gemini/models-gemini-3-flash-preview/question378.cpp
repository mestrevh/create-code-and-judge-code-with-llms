/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total_points = 0;
    int current_score;

    for (int i = 0; i < 6; ++i) {
        if (cin >> current_score) {
            total_points += current_score;
        }
    }

    if (total_points >= 100) {
        cout << "Classificado" << endl;
    } else {
        cout << "Eliminado" << endl;
    }

    return 0;
}