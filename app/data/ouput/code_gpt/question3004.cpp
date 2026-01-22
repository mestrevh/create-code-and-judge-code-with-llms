/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int recursivaSoma(const vector<int>& forças, int inicio, int fim) {
    if (inicio > fim) return 0;
    if (inicio == fim) return (forças[inicio] > 10) ? forças[inicio] : 0;

    int meio = inicio + (fim - inicio) / 2;
    return recursivaSoma(forças, inicio, meio) + recursivaSoma(forças, meio + 1, fim);
}

int main() {
    int N;
    cin >> N;
    vector<int> forças(N);
    for (int i = 0; i < N; i++) {
        cin >> forças[i];
    }
    cout << recursivaSoma(forças, 0, N - 1) << endl;
    return 0;
}
