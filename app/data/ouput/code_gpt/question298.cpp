/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int E, K, N;
    cin >> E >> K >> N;
    for (int i = 0; i < N; i++) {
        int SE, SA, DO;
        cin >> SE >> SA >> DO;
        E -= (K * 4 + SE + SA + DO);
        if (E < 0) {
            cout << i + 1 << " " << E << endl;
            return 0;
        }
    }
    cout << E << endl;
    return 0;
}
