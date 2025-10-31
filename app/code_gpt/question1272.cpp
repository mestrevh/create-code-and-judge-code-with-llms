/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int multiplicativePersistence(int n) {
    int steps = 0;
    while (n >= 10) {
        int product = 1;
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        n = product;
        steps++;
    }
    return steps;
}

int main() {
    int N;
    cin >> N;
    vector<int> results(N);

    for (int i = 0; i < N; ++i) {
        results[i] = -1;
    }

    for (int i = 0; ; ++i) {
        int pers = multiplicativePersistence(i);
        if (pers < N && (results[pers] == -1)) {
            results[pers] = i;
        }
        if (pers >= N && results[N-1] != -1) break;
    }

    for (int i = 0; i < N; ++i) {
        cout << "O menor número com persistência " << i << " é " << results[i] << ".\n";
    }
    return 0;
}
