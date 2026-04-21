/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    if (!(cin >> a >> b)) return 0;

    double result = a / b;

    cout.precision(2);
    cout << result << endl;

    return 0;
}