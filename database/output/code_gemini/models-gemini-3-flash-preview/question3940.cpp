/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

double calculate_salary(double min_wage, int pieces) {
    if (pieces <= 30) {
        return min_wage;
    } else if (pieces <= 41) {
        return min_wage + (pieces - 30) * (0.03 * min_wage);
    } else {
        return min_wage + (pieces - 30) * (0.05 * min_wage);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double min_wage;
    if (!(cin >> min_wage)) return 0;

    int p[3];
    double s[3];
    int total_pieces = 0;
    double max_sal = 0.0;

    for (int i = 0; i < 3; ++i) {
        cin >> p[i];
        s[i] = calculate_salary(min_wage, p[i]);
        total_pieces += p[i];
        if (s[i] > max_sal) max_sal = s[i];
    }

    double avg_pieces = static_cast<double>(total_pieces) / 3.0;

    cout << fixed << setprecision(2);
    cout << "Salario 1: " << s[0] << "\n";
    cout << "Salario 2: " << s[1] << "\n";
    cout << "Salario 3: " << s[2] << "\n";
    cout << "Total de pecas fabricadas: " << total_pieces << "\n";
    cout << "Media de pecas fabricadas: " << avg_pieces << "\n";
    cout << "Maior salario: " << max_sal << endl;

    return 0;
}