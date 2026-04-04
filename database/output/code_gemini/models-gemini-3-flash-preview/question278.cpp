/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, d;
    if (cin >> a >> b >> c >> d) {
        long long diff = (a * b) - (c * d);
        cout << "DIFERENCA = " << diff << endl;
    }

    return 0;
}