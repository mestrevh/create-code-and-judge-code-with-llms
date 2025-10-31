/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, count = 0;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0 && i % 3 == 0) {
            count++;
        }
    }
    
    if (count > 0) {
        cout << count << endl;
    } else {
        cout << "O numero nao possui divisores multiplos de 3!" << endl;
    }

    return 0;
}
