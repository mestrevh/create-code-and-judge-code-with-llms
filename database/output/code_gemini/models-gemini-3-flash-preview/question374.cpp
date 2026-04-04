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

    double salary;
    if (cin >> salary) {
        double bonus = salary * 0.75;

        if (bonus < 2000.0) {
            cout << "ARGENTINA" << endl;
        } else if (bonus <= 3000.0) {
            cout << "ESPANHA" << endl;
        } else {
            cout << "ALEMANHA" << endl;
        }
    }

    return 0;
}