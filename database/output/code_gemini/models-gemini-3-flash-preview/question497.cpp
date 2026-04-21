/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double ratings[5];
    double sum = 0.0;
    double max_val = -1.0;
    int max_idx = 0;

    for (int i = 0; i < 5; ++i) {
        if (!(cin >> ratings[i])) break;
        sum += ratings[i];
        if (ratings[i] > max_val) {
            max_val = ratings[i];
            max_idx = i;
        }
    }

    cout << fixed << setprecision(2) << (sum / 5.0) << "\n";

    if (max_idx == 0 || max_idx == 3) {
        cout << "NOVELA" << endl;
    } else if (max_idx == 1 || max_idx == 4) {
        cout << "FILME" << endl;
    } else if (max_idx == 2) {
        cout << "FUTEBOL" << endl;
    }

    return 0;
}