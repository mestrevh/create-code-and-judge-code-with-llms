/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

bool eh_divisivel(long long a, long long b) {
    if (b == 0) return false;
    return (a % b == 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (cin >> a >> b) {
        if (eh_divisivel(a, b)) {
            cout << "divisivel" << endl;
        } else {
            cout << "nao divisivel" << endl;
        }
    }

    return 0;
}