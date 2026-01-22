/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int reverseNumber(const vector<int>& digits, int index) {
    if (index < 0) return 0;
    return digits[index] * pow(10, digits.size() - 1 - index) + reverseNumber(digits, index - 1);
}

int sumReversedNumbers(int p) {
    int total = 0;
    for (int i = 0; i < p; ++i) {
        int n;
        cin >> n;
        vector<int> digits(n);
        for (int j = 0; j < n; ++j) {
            cin >> digits[j];
        }
        total += reverseNumber(digits, n - 1);
    }
    return total;
}

int main() {
    int p;
    cin >> p;
    cout << sumReversedNumbers(p) << endl;
    return 0;
}
