/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double current_grade;
    double previous_grade;
    bool wins_toy = true;

    if (!(cin >> previous_grade)) return 0;

    for (int i = 1; i < 6; ++i) {
        if (!(cin >> current_grade)) break;
        if (current_grade <= previous_grade) {
            wins_toy = false;
        }
        previous_grade = current_grade;
    }

    if (wins_toy) {
        cout << "Ganha brinquedo" << "\n";
    } else {
        cout << "Sem brinquedo" << "\n";
    }

    return 0;
}