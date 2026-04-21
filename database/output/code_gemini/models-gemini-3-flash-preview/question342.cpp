/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    if (!(cin >> N)) return 0;

    if (N <= 0) {
        cout << "O numero nao possui divisores multiplos de 3!" << endl;
        return 0;
    }

    long long count = 0;
    long long sqrtN = sqrt(N);

    for (long long i = 1; i <= sqrtN; ++i) {
        if (N % i == 0) {
            if (i % 3 == 0) {
                count++;
            }
            long long other = N / i;
            if (other != i) {
                if (other % 3 == 0) {
                    count++;
                }
            }
        }
    }

    if (count > 0) {
        cout << count << endl;
    } else {
        cout << "O numero nao possui divisores multiplos de 3!" << endl;
    }

    return 0;
}
坐