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

    char c;
    int i;
    float f;
    double d;

    while (cin >> c >> i >> f >> d) {
        cout << fixed << setprecision(2) << d << " " << f << " " << i << " " << c << "\n";
    }

    return 0;
}