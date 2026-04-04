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
    if (!(cin >> n)) return 0;

    long long tn = (n * (n + 1)) / 2;
    long long sn = (n * (n + 1) * (n + 2)) / 6;

    char parity;
    if (tn % 2 == 0 && sn % 2 == 0) {
        parity = 'P';
    } else if (tn % 2 != 0 && sn % 2 != 0) {
        parity = 'I';
    } else {
        parity = 'N';
    }

    cout << tn << " " << sn << " " << parity << "\n";

    return 0;
}

