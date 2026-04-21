/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    if (!(cin >> A >> B)) return 0;

    long long diff = A - B;
    if (diff <= 0) return 0;

    bool first = true;
    for (int i = 62; i >= 0; --i) {
        if ((diff >> i) & 1LL) {
            if (!first) {
                cout << " ";
            }
            cout << (1LL << i);
            first = false;
        }
    }
    cout << endl;

    return 0;
}