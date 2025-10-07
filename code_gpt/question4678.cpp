/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    if (N <= 0 || N > 10 || M <= 0 || M > 10) {
        cout << "Han??" << endl;
        return 0;
    }
    
    vector<vector<int>> fights(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> fights[i][j];

    int primeCount = 0;
    
    for (int i = 0; i < N; ++i) {
        int sum = accumulate(fights[i].begin(), fights[i].end(), 0);
        if (isPrime(sum)) ++primeCount;
    }
    
    if (primeCount > N / 2) {
        cout << "Chama" << endl;
    } else {
        cout << "Não chama" << endl;
    }
    
    return 0;
}
