/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int countDivisors(int n) {
    int count = 0;
    for (int i = 2; i <= abs(n) / 2; ++i) {
        if (n % i == 0) count++;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int M;
        cin >> M;
        long long total_reliability = 0;
        for (int i = 0; i < M; ++i) {
            int num;
            cin >> num;
            if (isPrime(abs(num))) {
                total_reliability += 2 * abs(num);
            } else {
                total_reliability += (abs(num) / 2) * countDivisors(num);
            }
        }
        if (total_reliability > (1 << 11)) {
            cout << "Anão Paulo. babado." << endl;
        } else if (total_reliability > (1 << 9)) {
            cout << "Para pow." << endl;
        } else if (total_reliability > 0) {
            cout << "Se isso não é mentira eu sou uma brastemp 4 portas" << endl;
        } else {
            cout << "que mentirada" << endl;
        }
    }
    return 0;
}
