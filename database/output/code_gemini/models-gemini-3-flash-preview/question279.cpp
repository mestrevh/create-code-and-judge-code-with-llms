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

    int id, hours;
    double rate;

    if (cin >> id >> hours >> rate) {
        double salary = static_cast<double>(hours) * rate;

        cout << "NUMBER = " << id << "\n";
        cout << "SALARY = R$ " << fixed << setprecision(2) << salary << "\n";
    }

    return 0;
}