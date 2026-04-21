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

    long long days;
    if (cin >> days) {
        double fine = (double)days * 0.75;
        cout << fixed << setprecision(2) << fine << "\n";
    }

    return 0;
}