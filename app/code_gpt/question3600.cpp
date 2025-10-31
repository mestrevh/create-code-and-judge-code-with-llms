/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> notas(n);
    for (int i = 0; i < n; i++) {
        cin >> notas[i];
    }

    int min_valid = *min_element(notas.begin(), notas.end());
    int cont = 0;

    for (int nota : notas) {
        if (nota < min_valid) {
            cont++;
        }
    }

    cout << cont << endl;
    cout << "Siga" << endl;

    return 0;
}
