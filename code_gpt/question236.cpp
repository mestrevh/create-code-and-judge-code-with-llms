/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void countDigits(long long A, long long B, vector<int>& digitCount) {
    for (long long i = A; i <= B; ++i) {
        string num = to_string(i);
        for (char c : num) {
            digitCount[c - '0']++;
        }
    }
}

int main() {
    while (true) {
        long long A, B;
        cin >> A >> B;
        if (A == 0 && B == 0) break;

        vector<int> digitCount(10, 0);
        countDigits(A, B, digitCount);

        for (int i = 0; i < 10; ++i) {
            cout << digitCount[i] << (i < 9 ? ' ' : '\n');
        }
    }
    return 0;
}
