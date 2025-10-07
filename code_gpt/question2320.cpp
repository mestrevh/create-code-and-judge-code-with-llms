/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

long long fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

int main() {
    vector<int> voltas;
    int y;

    while (cin >> y) {
        voltas.push_back(y);
    }

    long long totalArremessos = 0;

    for (int i = 0; i < voltas.size(); ++i) {
        long long arremessos = fatorial(voltas[i]);
        if (arremessos < 50) {
            arremessos *= 2;
        }
        cout << arremessos << endl;
        totalArremessos += voltas[i];
    }

    if (totalArremessos > 100) {
        cout << "WildCats, get the head in the game!" << endl;
    }

    return 0;
}
