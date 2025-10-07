/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        
        bool horario = true, anti_horario = true;
        
        for (int i = 0; i < n; ++i) {
            if (p[i] != (i + 1) && p[i] != (1 + (i + 1) % n)) {
                horario = false;
            }
            if (p[(n - i - 1) % n] != (i + 1) && p[(n - i - 1) % n] != (1 + (i + 1) % n)) {
                anti_horario = false;
            }
        }

        if (horario) {
            cout << "SIM, HORARIO\n";
        } else if (anti_horario) {
            cout << "SIM, ANTI-HORARIO\n";
        } else {
            cout << "NAO\n";
        }
    }
    return 0;
}
