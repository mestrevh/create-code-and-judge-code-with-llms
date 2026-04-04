/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, D;
    if (cin >> A >> B >> C >> D) {
        if (B > C && D > A && (C + D) > (A + B) && C > 0 && D > 0 && (A % 2 == 0)) {
            cout << "Valores aceitos" << endl;
        } else {
            cout << "Valores nao aceitos" << endl;
        }
    }

    return 0;
}