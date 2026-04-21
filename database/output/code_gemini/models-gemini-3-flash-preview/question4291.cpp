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

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        return 0;
    }

    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double current_grade;
        if (cin >> current_grade) {
            sum += current_grade;
        }
    }

    double average = sum / n;

    cout << setprecision(16) << average << "\n";

    return 0;
}