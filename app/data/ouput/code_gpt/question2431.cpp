/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int caso = 1; caso <= T; ++caso) {
        int N;
        cin >> N;
        cin.ignore();
        queue<int> regular, preferencial;
        cout << "Caso " << caso << ":\n";
        while (N--) {
            string comando;
            getline(cin, comando);
            if (comando[0] == 'f') {
                int x;
                sscanf(comando.c_str(), "f %d", &x);
                regular.push(x);
            } else if (comando[0] == 'p') {
                int x;
                sscanf(comando.c_str(), "p %d", &x);
                preferencial.push(x);
            } else if (comando[0] == 'A') {
                if (!regular.empty()) regular.pop();
            } else if (comando[0] == 'B') {
                if (!preferencial.empty()) preferencial.pop();
            } else if (comando[0] == 'I') {
                int r = regular.empty() ? 0 : regular.front();
                int p = preferencial.empty() ? 0 : preferencial.front();
                cout << r << " " << p << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
