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

    double n1, n2;
    while (cin >> n1 >> n2) {
        if (n2 == 0) continue;
        double result = n1 / n2;
        result = round(result * 100.0) / 100.0;
        cout << result << "\n";
    }

    return 0;
}