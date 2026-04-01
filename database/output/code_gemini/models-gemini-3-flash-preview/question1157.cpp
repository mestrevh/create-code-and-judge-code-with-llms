/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, A;
    if (cin >> L >> A) {
        long long volume = L * L * A;
        cout << volume << endl;
    }

    return 0;
}