/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, L, C, totalCoposQuebrados = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> L >> C;
        if (L > C) {
            totalCoposQuebrados += C;
        }
    }
    cout << totalCoposQuebrados << endl;
    return 0;
}
