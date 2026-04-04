/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ig, ia, e, i, s;
    if (!(cin >> ig >> ia >> e >> i >> s)) return 0;

    bool req1 = (ig == 1 || ia == 1);
    bool req2 = (e == 1 && i == 1);
    bool req3 = (s == 1);

    if (req1 && req2 && req3) {
        cout << "AVALIADO" << "\n";
    } else {
        cout << "0" << "\n";
    }

    return 0;
}

