/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n > 0) {
        long long total_students = 0;
        for (int i = 0; i < n; ++i) {
            int students;
            while (cin >> students) {
                if (students <= 40) {
                    total_students += students;
                    break;
                } else {
                    cout << "O numero de alunos nao pode ser maior que 40" << endl;
                }
            }
        }

        double average = static_cast<double>(total_students) / n;
        long long rounded_average = static_cast<long long>(round(average));
        cout << rounded_average << endl;
    }

    return 0;
}