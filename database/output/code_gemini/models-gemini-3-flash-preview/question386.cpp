/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double total = 0.0;
    double previous_value;
    double current_value;
    int success_count = 0;

    if (!(cin >> previous_value)) {
        return 0;
    }

    total += previous_value;

    for (int i = 1; i < 7; ++i) {
        if (!(cin >> current_value)) {
            break;
        }
        total += current_value;
        if (current_value >= previous_value + 0.5 - 1e-9) {
            success_count++;
        }
        previous_value = current_value;
    }

    cout << "R$ " << fixed << setprecision(2) << total << "\n";
    cout << success_count << endl;

    return 0;
}