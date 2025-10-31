/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int alturaArvore(int N, int K) {
    if (K == 1) return 1;
    return 1 + alturaArvore(N, K / N);
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << alturaArvore(N, K) << endl;
    return 0;
}
