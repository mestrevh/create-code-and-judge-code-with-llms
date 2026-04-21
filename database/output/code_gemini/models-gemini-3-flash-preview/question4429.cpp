/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, a, p, d;
    while (cin >> k >> a >> p >> d) {
        // Ataque rápido: se o cavaleiro estiver dormindo (k == 0)
        int a1 = (k == 0 ? 1 : 0);
        
        // Espionar: se pelo menos um deles estiver acordado (k, a, ou p)
        // Teste 1 (0 0 1 0 -> 1 1 1 1) confirma que o prisioneiro (p) conta.
        int a2 = (k == 1 || a == 1 || p == 1 ? 1 : 0);
        
        // Sinalizar: se o prisioneiro estiver acordado (p == 1) e o arqueiro dormindo (a == 0)
        int a3 = (p == 1 && a == 0 ? 1 : 0);
        
        // Resgatar:
        // Caso Mia tenha o cachorro (d == 1): arqueiro deve estar dormindo (a == 0)
        // Caso Mia não tenha o cachorro (d == 0): prisioneiro acordado (p == 1),
        // cavaleiro dormindo (k == 0) e arqueiro dormindo (a == 0)
        int a4 = 0;
        if (d == 1) {
            if (a == 0) a4 = 1;
        } else {
            if (p == 1 && k == 0 && a == 0) a4 = 1;
        }

        cout << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
    }

    return 0;
}