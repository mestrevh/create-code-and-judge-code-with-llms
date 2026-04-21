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
    if (cin >> n) {
        int dozens = n / 12;
        double total_price = (static_cast<double>(n) * 8.35) / 12.0;

        cout << dozens << "\n";
        cout << fixed << setprecision(2) << total_price << "\n";
    }

    return 0;
}