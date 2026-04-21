/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        bool first = true;
        for (long long i = 0; i <= n; i += 2) {
            if (!first) {
                cout << "   ";
            }
            cout << i;
            first = false;
        }
        cout << endl;
    }

    return 0;
}