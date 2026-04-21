/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, d, x;
    if (!(cin >> a >> b >> c >> d >> x)) return 0;

    long long result = ((a * x + b) * x + c) * x + d;

    cout << result << endl;

    return 0;
}