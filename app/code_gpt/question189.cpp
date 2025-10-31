/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    int count = 0;

    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            count++;
            if (i != N / i) count++;
        }
    }

    cout << count / 2 << endl;
    return 0;
}
