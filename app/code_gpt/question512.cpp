/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; caso++) {
        int N;
        cin >> N;
        int soma = N * N * N;
        int primeiro = (N - 1) * (N - 1) + 1;
        cout << "caso " << caso << ": ";
        for (int i = 0; i < N; i++) {
            cout << primeiro + 2 * i;
            if (i < N - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
