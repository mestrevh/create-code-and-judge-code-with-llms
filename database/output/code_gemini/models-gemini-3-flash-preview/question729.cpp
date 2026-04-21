/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string gabarito;
    if (!(cin >> gabarito)) return 0;

    int m;
    if (!(cin >> m)) return 0;

    while (m--) {
        string resposta;
        if (!(cin >> resposta)) break;
        int nota = 0;
        int len = (int)resposta.length();
        for (int i = 0; i < n && i < len; ++i) {
            if (resposta[i] == gabarito[i]) {
                nota++;
            }
        }
        cout << nota << "\n";
    }

    return 0;
}