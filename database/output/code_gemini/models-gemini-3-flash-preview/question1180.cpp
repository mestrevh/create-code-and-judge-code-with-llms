/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (!(cin >> a >> b)) return 0;

    int h12 = (a % 12 == 0) ? 12 : a % 12;
    string period = (a < 12) ? "am" : "pm";

    cout << setfill('0') << setw(2) << h12 << "\n";
    cout << setfill('0') << setw(2) << b << "\n";
    cout << period << "\n";

    return 0;
}

