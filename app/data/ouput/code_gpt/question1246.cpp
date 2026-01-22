/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

long long sumOfRow(int K) {
    long long start = (K * (K - 1) / 2) + 1;
    long long end = start + K - 1;
    return (start + end) * K / 2;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int K;
        cin >> K;
        cout << sumOfRow(K) << endl;
    }
    return 0;
}
