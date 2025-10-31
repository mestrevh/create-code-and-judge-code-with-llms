/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> moedas(N);
    for (int i = 0; i < N; i++) {
        cin >> moedas[i];
    }

    int totalMoedas = 0, pos = 0;
    string comando;

    while (cin >> comando) {
        char sentido = comando[0];
        int saltos = stoi(comando.substr(1));
        
        if (sentido == '+') {
            pos = (pos + saltos) % N;
        } else if (sentido == '-') {
            pos = (pos - saltos % N + N) % N;
        }

        totalMoedas += moedas[pos];
        moedas[pos] = 0;
    }

    cout << totalMoedas << endl;
    return 0;
}
