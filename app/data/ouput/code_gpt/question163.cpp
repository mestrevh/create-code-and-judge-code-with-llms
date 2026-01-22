/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int P, N;
    cin >> P >> N;
    vector<int> pastas(N);
    unordered_map<int, int> contador;

    for (int i = 0; i < N; ++i) {
        cin >> pastas[i];
        contador[pastas[i]]++;
    }

    for (int i = 1; i <= P; ++i) {
        if (contador[i] < contador[i - 1] && i > 1) {
            cout << "N" << endl;
            return 0;
        }
    }

    if (contador[1] < contador[P]) {
        cout << "N" << endl;
        return 0;
    }

    cout << "S" << endl;
    return 0;
}
