/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, num, soma = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        soma += num;
    }
    cout << soma << endl;
    return 0;
}
