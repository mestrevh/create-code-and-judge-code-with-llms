/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (cin >> a >> b) {
        for (long long x = a; x <= b; ++x) {
            long long result = (x * x) - (4 * x) + 5;
            cout << result << "\n";
        }
    }

    return 0;
}